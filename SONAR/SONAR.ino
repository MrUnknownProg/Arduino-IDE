#include <LiquidCrystal_I2C.h>
#include<Wire.h>
// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;
const int Buzzer = 9;
// Variables for the duration and the distance
long duration;
float distance;
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  pinMode(Buzzer,OUTPUT);//Buzzer as OUTPUT
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
}
void loop() {
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  Serial.print(" ,"); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distance); // Sends the distance value into the Serial Port
  Serial.print(".0 cm"); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing

  //print output on lcd display
  lcd.print(distance);
  lcd.setCursor(3, 0);
  //lcd.print("cm");
  if(distance<10)
  {
    digitalWrite(Buzzer,HIGH);
    lcd.setCursor(2,1);
    lcd.print("TOO Close");
    delay(2000);
    lcd.clear();
  }
  else
  {
    digitalWrite(Buzzer,LOW);
    return;
  }
   if(distance>20)
    {
      lcd.setCursor(2,1);
      lcd.print("TOO BIGGG!!");
      delay(2000);
    }
  else
    {
        delay(2000);
    }
  lcd.clear();
  }
  
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}


