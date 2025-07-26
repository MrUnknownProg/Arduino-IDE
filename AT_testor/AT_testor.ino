#include <Arduino.h>
#include <SoftwareSerial.h>

// RX (Arduino D10) ← TXD of A7670C
// TX (Arduino D11) → RXD of A7670C (via voltage divider)
SoftwareSerial a7670Serial(2, 3);  // RX, TX

// Send command and wait for response
void SendATCommand(String command) {
  Serial.println(">> " + command);          // Show the command
  a7670Serial.println(command);             // Send to A7670C

  unsigned long timeout = millis() + 5000;  // 5-second timeout
  while (millis() < timeout) {
    while (a7670Serial.available()) {
      String response = a7670Serial.readStringUntil('\n');
      response.trim();
      if (response.length() > 0) {
        Serial.println("<< " + response);
        if (response == "OK" || response == "ERROR") return;
      }
    }
  }
  Serial.println("<< (Timeout)");
}

void setup() {
  Serial.begin(115200);          // For Serial Monitor
  a7670Serial.begin(115200);   // A7670C default baud rate

  Serial.println("Initializing A7670C...");
  
  delay(3000); // Wait for module to boot

  // Send test AT commands
  SendATCommand("AT");                // Basic test
  SendATCommand("ATE0");              // Echo off
  SendATCommand("AT+CPIN?");          // Check SIM status
  SendATCommand("AT+CSQ");            // Signal quality
  SendATCommand("AT+CREG?");          // Network registration
  SendATCommand("AT+CGATT?");         // GPRS attach status
}

void loop() {
  // nothing here
  delay(10);
}

