#include <WiFi.h>
#include <PubSubClient.h>
#include <Update.h>
#include "esp_task_wdt.h"

#define WIFI_SSID ""
#define WIFI_PASS ""
#define MQTT_BROKER "192.168.X.X"  // Replace with your MQTT broker IP
#define MQTT_TOPIC "esp32/fota"

WiFiClient espClient;
PubSubClient client(espClient);
String base64Firmware = "";
bool updateFlag = false;

// Base64 decoding function
String decodeBase64(const String &input) {
    const char* b64chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int inLen = input.length();
    int outLen = (inLen / 4) * 3;
    
    String decoded;
    decoded.reserve(outLen);
    
    int i = 0, j = 0;
    uint8_t charArray[4];

    while (inLen-- && (input[i] != '=') && (isalnum(input[i]) || input[i] == '+' || input[i] == '/')) {
        charArray[j++] = input[i++];
        if (j == 4) {
            for (int k = 0; k < 4; k++) 
                charArray[k] = strchr(b64chars, charArray[k]) - b64chars;

            decoded += (char)((charArray[0] << 2) | (charArray[1] >> 4));
            decoded += (char)((charArray[1] << 4) | (charArray[2] >> 2));
            decoded += (char)((charArray[2] << 6) | charArray[3]);

            j = 0;
        }
    }
    return decoded;
}

// Connect to WiFi
void connectWiFi() {
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(1000);
    }
    Serial.println("\nWiFi Connected");
}

// Connect to MQTT Broker
void connectMQTT() {
    client.setServer(MQTT_BROKER, 1883);
    client.setCallback(mqttCallback);

    while (!client.connected()) {
        Serial.print("Connecting to MQTT...");
        if (client.connect("ESP32_FOTA_Client")) {
            Serial.println("Connected");
            client.subscribe(MQTT_TOPIC);
        } else {
            Serial.print("Failed, rc=");
            Serial.print(client.state());
            Serial.println(" Trying again...");
            delay(2000);
        }
    }
}

// MQTT Callback - Handles incoming firmware
void mqttCallback(char* topic, byte* payload, unsigned int length) {
    Serial.println("New FOTA Update Received!");

    base64Firmware = ""; // Reset firmware buffer
    base64Firmware.reserve(length); // Avoid memory fragmentation
    for (unsigned int i = 0; i < length; i++) {
        base64Firmware += (char)payload[i];
    }

    updateFlag = true; // Set update flag for loop processing
}

// Apply firmware update
void applyFirmwareUpdate() {
    Serial.println("Decoding Base64...");

    String binaryFirmware = decodeBase64(base64Firmware);
    int binLength = binaryFirmware.length();
    Serial.printf("Decoded firmware size: %d bytes\n", binLength);

    if (binLength == 0) {
        Serial.println("Decoding failed, aborting update.");
        return;
    }

    Serial.println("Starting OTA Update...");
    if (Update.begin(binLength)) {
        Update.write((uint8_t*)binaryFirmware.c_str(), binLength);
        if (Update.end()) {
            Serial.println("OTA Update Successful! Restarting...");
            ESP.restart();
        } else {
            Serial.printf("OTA Update Failed: %s\n", Update.errorString());
        }
    } else {
        Serial.println("Not Enough Space for Update");
    }
}

// Setup function
void setup() {
    Serial.begin(115200);
    connectWiFi();
    connectMQTT();


    #if ESP_IDF_VERSION_MAJOR >= 5
        esp_task_wdt_config_t wdtConfig = {
            .timeout_ms = 30000, // 30 seconds
            .idle_core_mask = (1 << CONFIG_ESP_MAIN_TASK_AFFINITY),
            .trigger_panic = true
        };
        esp_task_wdt_init(&wdtConfig);
    #else
        esp_task_wdt_init(30, true); // 30s timeout, manual reset required
    #endif

    esp_task_wdt_add(NULL); // Attach watchdog to main task
}

// Main loop
void loop() {
    client.loop(); // Handle MQTT messages

    if (updateFlag) {
        updateFlag = false;  // Reset flag
        applyFirmwareUpdate();
    }

    esp_task_wdt_reset(); // Reset watchdog to prevent timeout
    delay(10);  

