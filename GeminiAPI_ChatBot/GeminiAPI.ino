#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

// Wi-Fi credentials
const char* ssid = "";
const char* password = "";
const char* Gemini_Token = "AIzaSyBidAD2UkOwRFHx9JYBcR9_3Nsaac4hO8Q";
const int Gemini_Max_Tokens = 100;

// Restricted words list
const char* restrictedWords[] = {"badword1", "badword2", "inappropriate", "restricted"};
const int restrictedWordsCount = sizeof(restrictedWords) / sizeof(restrictedWords[0]);

String res = "";

// Function to connect to Wi-Fi
void connectWiFi() {
  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

// Function to check for restricted words
bool containsRestrictedWords(const String& text) {
  for (int i = 0; i < restrictedWordsCount; i++) {
    if (text.indexOf(restrictedWords[i]) != -1) {
      return true;  // Restricted word found
    }
  }
  return false;
}

// Function to filter special characters from the response
String getFilteredAnswer(String answer) {
  answer.trim();
  String filteredAnswer = "";
  for (size_t i = 0; i < answer.length(); i++) {
    char c = answer[i];
    if (isalnum(c) || isspace(c)) {
      filteredAnswer += c;
    } else {
      filteredAnswer += ' ';
    }
  }
  return filteredAnswer;
}

// Function to send a question to the Gemini API and parse the response
void askQuestion(String question) {
  WiFiClientSecure client;
  client.setInsecure();  // Skip certificate verification (for testing)

  if (client.connect("generativelanguage.googleapis.com", 443)) {
    Serial.println("[HTTPS] Connected to server");

    String url = "/v1beta/models/gemini-1.5-flash:generateContent?key=" + String(Gemini_Token);
    String payload = String("{\"contents\": [{\"parts\":[{\"text\":\"" + question + "\"}]}],\"generationConfig\": {\"maxOutputTokens\": ") + Gemini_Max_Tokens + "}}";

    // Send HTTP POST request
    client.println("POST " + url + " HTTP/1.1");
    client.println("Host: generativelanguage.googleapis.com");
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(payload.length());
    client.println();
    client.println(payload);

    // Wait for response
    while (client.connected()) {
      String line = client.readStringUntil('\n');
      if (line == "\r") break;  // Headers end with an empty line
    }

    String response = client.readString();
    Serial.println("Response:");
    Serial.println(response);  // Debugging: Print full response

    // Parse JSON
    DynamicJsonDocument doc(4096);  // Adjusted memory allocation
    DeserializationError error = deserializeJson(doc, response);

    if (!error) {
      // Extract answer from JSON
      String answer = doc["candidates"][0]["content"]["parts"][0]["text"];

      // Check if the response contains restricted words
      if (containsRestrictedWords(answer)) {
        Serial.println("The response contains restricted content and cannot be displayed.");
      } else {
        Serial.println("\nHere is your Answer: ");
        Serial.println(getFilteredAnswer(answer));
      }
    } else {
      Serial.print("[JSON] Parsing failed: ");
      Serial.println(error.c_str());  // Print error message
    }
  } else {
    Serial.println("[HTTPS] Connection failed!");
  }

  client.stop();
}

// Main Arduino setup function
void setup() {
  Serial.begin(115200);
  while (!Serial);  // Wait for Serial
  connectWiFi();
}

// Main Arduino loop function
void loop() {
  Serial.println("\nAsk your Question: ");
  while (!Serial.available());
  String question = Serial.readStringUntil('\n');
  question.trim();

  // Check if the user input contains restricted words
  if (containsRestrictedWords(question)) {
    Serial.println("Your input contains restricted words and cannot be processed.");
  } else if (!question.isEmpty()) {
    Serial.println("\nAsking Your Question...");
    askQuestion(question);
  }
}
