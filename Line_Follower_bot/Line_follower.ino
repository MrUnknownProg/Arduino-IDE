#include <Wire.h>

//SCL d1
//SDA d2

int IN1 = 2;  // Direction pin 1 for Motor 1, D4
int IN2 = 0;  // Direction pin 2 for Motor 1, D3

int IN3 = 12; // Direction pin 1 for Motor 2, D6
int IN4 = 13; // Direction pin 2 for Motor 2, D7

int L_S = 14; // Left IR sensor pin, D5
int R_S = 15;  // Right IR sensor pin, D8

void setup() {
  Serial.begin(115200);
  // Set all the motor control pins to outputs

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(L_S, INPUT);
  pinMode(R_S, INPUT);

}

void irprint() {
  if (!digitalRead(R_S)) { // Check if the right sensor detects line
    Serial.println("Right Side Detected");
  }
  if (!digitalRead(L_S)) { // Check if the left sensor detects line
    Serial.println("Left Side Detected");
  }
}

void forward() {
  // Test Motor 1

  digitalWrite(IN1, HIGH);   // Forward direction
  digitalWrite(IN2, LOW);

  // Test Motor 2

  digitalWrite(IN3, HIGH);   // Forward direction
  digitalWrite(IN4, LOW);
}

void brake() {
  // Turn off both motors
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void reverse() {
  // Reverse Motor 1
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Reverse Motor 2
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void loop() {
  forward();
  delay(1000);
  brake();
  delay(1000);
  reverse();
  delay(1000);
  irprint(); 
}