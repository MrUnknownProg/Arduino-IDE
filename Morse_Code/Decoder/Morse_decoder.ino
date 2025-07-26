String in = "";
String A = ".-";
String B = "-...";
String C = "-.-.";
String D = "-..";
String E = ".";
String F = "..-.";
String G = "--.";
String H = "....";
String I = "..";
String J = ".---";
String K = "-.-";
String L = ".-..";
String M = "--";
String N = "-.";
String O = "---";
String P = ".--.";
String Q = "--.-";
String R = ".-.";
String S = "...";
String T = "-";
String U = "..-";
String V = "...-";
String W = ".--";
String X = "-..-";
String Y = "-.--";
String Z = "--..";
String SPACE = "_";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    in = Serial.readString();
    in.trim();
    {
      if (in.equals(A)) {
        Serial.print("A");
      } else if (in.equals(B)) {
        Serial.print("B");
      } else if (in.equals(C)) {
        Serial.print("C");
      } else if (in.equals(D)) {
        Serial.print("D");
      } else if (in.equals(E)) {
        Serial.print("E");
      } else if (in.equals(F)) {
        Serial.print("F");
      } else if (in.equals(G)) {
        Serial.print("G");
      } else if (in.equals(H)) {
        Serial.print("H");
      } else if (in.equals(I)) {
        Serial.print("I");
      } else if (in.equals(J)) {
        Serial.print("J");
      } else if (in.equals(K)) {
        Serial.print("K");
      } else if (in.equals(L)) {
        Serial.print("L");
      } else if (in.equals(M)) {
        Serial.print("M");
      } else if (in.equals(N)) {
        Serial.print("N");
      } else if (in.equals(O)) {
        Serial.print("O");
      } else if (in.equals(P)) {
        Serial.print("P");
      } else if (in.equals(Q)) {
        Serial.print("Q");
      } else if (in.equals(R)) {
        Serial.print("R");
      } else if (in.equals(S)) {
        Serial.print("S");
      } else if (in.equals(T)) {
        Serial.print("T");
      } else if (in.equals(U)) {
        Serial.print("U");
      } else if (in.equals(V)) {
        Serial.print("V");
      } else if (in.equals(W)) {
        Serial.print("W");
      } else if (in.equals(X)) {
        Serial.print("X");
      } else if (in.equals(Y)) {
        Serial.print("Y");
      } else if (in.equals(Z)) {
        Serial.print("Z");
      } else if (in.equals(SPACE)) {
        Serial.print(" ");
      } else {
        Serial.println("INVAILD CHARACTER ENCOUNTERED");
      }
    }
  }
}
