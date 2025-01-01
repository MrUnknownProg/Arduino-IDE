#define RED 10
#define GREEN 9
#define BLUE 6
#define DELAY 5000
void setup() {
  // put your setup code here, to run once:
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(RED,127);
  analogWrite(GREEN,0); //Violet
  analogWrite(BLUE,255);
  delay(DELAY);
  analogWrite(RED,75);
  analogWrite(GREEN,0); //Indigo
  analogWrite(BLUE,130);
  delay(DELAY);
  analogWrite(RED,0);
  analogWrite(GREEN,0); //Blue
  analogWrite(BLUE,255);
  delay(DELAY);
  analogWrite(RED,0);
  analogWrite(GREEN,255); //Green
  analogWrite(BLUE,0);
  delay(DELAY);
  analogWrite(RED,255);
  analogWrite(GREEN,255); //Yellow
  analogWrite(BLUE,0);
  delay(DELAY);
  analogWrite(RED,255);
  analogWrite(GREEN,165); //Orange
  analogWrite(BLUE,0);
  delay(DELAY);
  analogWrite(RED,255);
  analogWrite(GREEN,0); //Red
  analogWrite(BLUE,0);
  delay(DELAY);
}
