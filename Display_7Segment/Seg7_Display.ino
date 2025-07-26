#define A 9
#define B 13
#define C 5
#define D 3
#define E 2
#define F 10
#define G 6
#define DP 4
#define D1 8
#define D2 11
#define D3 12
#define D4 7

void setup() {
  // put your setup code here, to run once:
pinMode(A,OUTPUT);
pinMode(B,OUTPUT);
pinMode(C,OUTPUT);
pinMode(D,OUTPUT);
pinMode(E,OUTPUT);
pinMode(F,OUTPUT);
pinMode(G,OUTPUT);
pinMode(DP,OUTPUT);
pinMode(D1,OUTPUT);
pinMode(D2,OUTPUT);
pinMode(D3,OUTPUT);
pinMode(D4,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //COUNT 0-10
  //ZERO
  digitalWrite(D1,HIGH);
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,HIGH);
  digitalWrite(E,HIGH);
  digitalWrite(F,HIGH);
  delay(1500);
  digitalWrite(D1,LOW);
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  //ONE
 digitalWrite(D1,HIGH);
 digitalWrite(B,HIGH);
 digitalWrite(C,HIGH);
 delay(1500);
 digitalWrite(D1,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
  //TWO
 digitalWrite(D1,HIGH);
 digitalWrite(A,HIGH);
 digitalWrite(B,HIGH);
 digitalWrite(C,HIGH);
 digitalWrite(D,HIGH);
 digitalWrite(G,HIGH);
 delay(1500);
 digitalWrite(D1,LOW);
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(G,LOW);
 //THREE
 digitalWrite(D1,HIGH);
 digitalWrite(A,HIGH);
 digitalWrite(B,HIGH);
 digitalWrite(C,HIGH);
 digitalWrite(D,HIGH);
 digitalWrite(G,HIGH);
 delay(1500);
 digitalWrite(D1,LOW);
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(G,LOW);
 //FOUR
 digitalWrite(D1,HIGH);
 digitalWrite(B,HIGH);
 digitalWrite(C,HIGH);
 digitalWrite(G,HIGH);
 digitalWrite(F,HIGH);
 delay(1500);
 digitalWrite(D1,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(G,LOW);
 digitalWrite(F,LOW);
 //FIVE
 digitalWrite(D1,HIGH);
 digitalWrite(A,HIGH);
 digitalWrite(C,HIGH);
 digitalWrite(D,HIGH);
 digitalWrite(G,HIGH);
 digitalWrite(F,HIGH);
 delay(1500);
 digitalWrite(D1,LOW);
 digitalWrite(A,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(G,LOW);
 digitalWrite(F,LOW);
 //SIX
 digitalWrite(D1,HIGH);
 digitalWrite(A,HIGH);
 digitalWrite(C,HIGH);
 digitalWrite(D,HIGH);
 digitalWrite(E,HIGH);
 digitalWrite(F,HIGH);
 digitalWrite(G,HIGH);
 delay(1500);
 digitalWrite(D1,LOW);
 digitalWrite(A,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F,LOW);
 digitalWrite(G,LOW);
 //SEVEN
 digitalWrite(D1,HIGH);
 digitalWrite(A,HIGH);
 digitalWrite(B,HIGH);
 digitalWrite(C,HIGH);
 delay(1500);
 digitalWrite(D1,LOW);
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 //EIGHT
 digitalWrite(D1,HIGH);
 digitalWrite(A,HIGH);
 digitalWrite(B,HIGH);
 digitalWrite(C,HIGH);
 digitalWrite(D,HIGH);
 digitalWrite(F,HIGH);
 digitalWrite(G,HIGH);

 delay(1500);
 digitalWrite(D1,LOW);
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(F,LOW);
 digitalWrite(G,LOW);
 
 //NINE
 digitalWrite(D1,HIGH);
 digitalWrite(A,HIGH);
 digitalWrite(B,HIGH);
 digitalWrite(C,HIGH);
 digitalWrite(D,HIGH);
 digitalWrite(F,HIGH);
 digitalWrite(G,HIGH);
 delay(1500);
 digitalWrite(D1,LOW);
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(F,LOW);
 digitalWrite(G,LOW);

 


 //TEN
 for(int i=0;i<100;i++)
 {
  //ONE
 digitalWrite(D1,HIGH);
 digitalWrite(B,HIGH);
 digitalWrite(C,HIGH);
 delay(10);
 digitalWrite(D1,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
  //ZERO
 digitalWrite(D2,HIGH);
 digitalWrite(A,HIGH);
 digitalWrite(B,HIGH);
 digitalWrite(C,HIGH);
 digitalWrite(D,HIGH);
 digitalWrite(E,HIGH);
 digitalWrite(F,HIGH);
 delay(10);
 digitalWrite(D2,LOW);
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F,LOW);
 }



}
