#include <IRremote.hpp>

#define Recvpin 4
void setup() {
  Serial.begin(9600);
  IrReceiver.begin(Recvpin);
  Serial.print("Ready:-");
}
void loop() {
  if (IrReceiver.decode()) {
    Serial.print(IrReceiver.decodedIRData.decodedRawData, HEX);
    delay(2000);
    IrReceiver.resume();
  }
}