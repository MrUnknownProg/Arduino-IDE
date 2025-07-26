#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

// Wi-Fi Credentials
const char* ssid = "vivoY31";
const char* password = "abcd1234";

// ThingSpeak Credentials
const char* apiKey = "Y6M714IEOE5GMQOY";
const unsigned long channelID = 2855121 ;

// Sensor Pin
const int sensorPin = A0;  // ESP8266 has only one ADC pin (A0)

WiFiClient client;

void setup() {
    Serial.begin(115200);
    
    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nConnected to Wi-Fi");
    
    ThingSpeak.begin(client);
}

void loop() {
    // Read sensor data
    int sensorValue = analogRead(sensorPin);
   
    Serial.print("Analog Value: ");
    Serial.print(sensorValue);

    // Send data to ThingSpeak
    ThingSpeak.setField(1, sensorValue);
    
    int response = ThingSpeak.writeFields(channelID, apiKey);
    if (response == 200) {
        Serial.println("Data sent successfully.");
    } else {
        Serial.print("Error sending data. Code: ");
        Serial.println(response);
    }

    delay(15000);  // ThingSpeak allows data upload every 15 seconds
}