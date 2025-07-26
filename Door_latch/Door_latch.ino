#include <Servo.h>
#define irsensor 13
#define buzz 4
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;  // variable to store the servo position
int readpin;
void setup() {
  myservo.attach(2);  // attaches the servo on pin 9 to the servo object
  pinMode(irsensor, INPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  readpin = digitalRead(irsensor);
  if (readpin == LOW) {
    for (pos = 0; pos <= 180; pos += 1) {  // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);  // tell servo to go to position in variable 'pos'
      digitalWrite(buzz, HIGH);
      delay(15);  // waits 15 ms for the servo to reach the position
      digitalWrite(buzz, LOW);
    }
  } else {
    for (pos = 180; pos >= 0; pos -= 1) {  // goes from 180 degrees to 0 degrees
      myservo.write(pos);                  // tell servo to go to position in variable 'pos'
      digitalWrite(buzz, HIGH);
      delay(15);  // waits 15 ms for the servo to reach the position
      digitalWrite(buzz, LOW);
    }
  }
}
