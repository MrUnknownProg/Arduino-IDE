#include <HardwareSerial.h>

HardwareSerial gsmSerial(2);  // Use UART2 (RX = 16, TX = 17)

void setup() {
    Serial.begin(115200);
    gsmSerial.begin(115200, SERIAL_8N1, , );  // GSM module baud rate

    Serial.println("Initializing GSM module...");
    delay(1000);
}

void loop() {
    if (gsmSerial.available()) {
        Serial.write(gsmSerial.read());
    }
    if (Serial.available()) {
        gsmSerial.write(Serial.read());
    }
}

void sendATCommand(String command) {
    Serial.print("Sending: ");
    Serial.println(command);
    gsmSerial.println(command);
    delay(1000);
    while (gsmSerial.available()) {
        Serial.write(gsmSerial.read());
    }
    Serial.println();
}
