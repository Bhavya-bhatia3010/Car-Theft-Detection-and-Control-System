#include <TinyGPS++.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ESPAsyncWebServer.h> // For web server 
#include <AsyncTCP.h>
// Wi-Fi and ThingSpeak credentials
const char* ssid = "";//hotspot/WI-FI name
const char* password = "";
const char* apiWriteKey = "ILWFCWSX5PJMGE4E";//IDS from Thingspeak
const char* apiReadKey = "LBZ77YJ8JEOX60XX";
const char* channelID = "2745605";
const char* thingspeakServer = "http://api.thingspeak.com";
// GPS and motor/relay pins
TinyGPSPlus gps;
#define RX2 16
#define TX2 17
HardwareSerial gpsSerial(2);
#define IN1 18
#define IN2 19
#define RELAY_PIN 21
// Initialize the web server on port 80
AsyncWebServer server(80);

// Function prototypes
void connectToWiFi();
void sendToThingSpeak(double lat, double lng);
void handleStartStopCommand(String command);
void setup() {
  Serial.begin(115200); // For debugging
  gpsSerial.begin(9600, SERIAL_8N1, RX2, TX2);
  // Initialize pins
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Ensure relay starts OFF (Active Low logic)
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  // Connect to Wi-Fi
  connectToWiFi();
  // Serve Start Command
  server.on("/start", HTTP_GET, [](AsyncWebServerRequest * request) {
    handleStartStopCommand("START");
    request->send(200, "text/plain", "Car Started");
  });
  // Serve Stop Command
  server.on("/stop", HTTP_GET, [](AsyncWebServerRequest * request) {
    handleStartStopCommand("STOP");
    request->send(200, "text/plain", "Car Stopped");
  });
  // Serve Reverse Command
  server.on("/reverse", HTTP_GET, [](AsyncWebServerRequest * request) {
    handleStartStopCommand("REVERSE");
    request->send(200, "text/plain", "Car in Reverse");
  });
  // Start the server
  server.begin();
}
void loop() {
  // Check GPS data
  while (gpsSerial.available() > 0) {
    char c = gpsSerial.read();
    if (gps.encode(c)) {
      
      if (gps.location.isValid()) {
        double latitude = gps.location.lat();
        double longitude = gps.location.lng();
        // Print latitude and longitude to the serial monitor
        Serial.printf("Latitude: %.6f, Longitude: %.6f\n", latitude, longitude);
        // Send GPS data to ThingSpeak
        sendToThingSpeak(latitude, longitude);
      }
    }
  }
  delay(10000); // Delay for 10 seconds
}
void connectToWiFi() {
  WiFi.begin(ssid, password);
  int retryCount = 0;
  while (WiFi.status() != WL_CONNECTED && retryCount < 10) {
    delay(1000);
    retryCount++;
    Serial.println("Connecting to Wi-Fi...");
  }
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Failed to connect to Wi-Fi.");
  } else {
    Serial.println("Connected to Wi-Fi.");
    Serial.print("ESP32 IP Address: ");
    Serial.println(WiFi.localIP());
  }
}
void sendToThingSpeak(double lat, double lng) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    
    // Construct the URL to send the GPS data to ThingSpeak
    String url = String(thingspeakServer) + "/update?api_key=" + apiWriteKey +
                 "&field1=" + String(lat, 6) + "&field2=" + String(lng, 6);
    // Debugging Log: Print the URL being sent
    Serial.print("URL: ");
    Serial.println(url);
    http.begin(url);
    int httpCode = http.GET();
    // Debugging Log: Print the HTTP Response Code
    Serial.print("HTTP Response: ");
    Serial.println(httpCode);
    if (httpCode == HTTP_CODE_OK) {
      Serial.println("Data sent to ThingSpeak successfully.");
    } else {
      Serial.print("Failed to send data. HTTP code: ");
      Serial.println(httpCode);
    }
    http.end(); // Free resources
  } else {
    Serial.println("Wi-Fi disconnected! Cannot send data.");
  }
}
void handleStartStopCommand(String command) {
  Serial.println("Received Command: " + command); // Debug
  if (command == "START") {
    digitalWrite(RELAY_PIN, LOW);  // Energize the relay (Active Low logic)
    digitalWrite(IN1, HIGH);
    // Forward motion
    digitalWrite(IN2, LOW);
    Serial.println("Car started. Moving forward.");
  } else if (command == "STOP") {
    digitalWrite(RELAY_PIN, HIGH);   // De-energize the relay (Active Low logic)
    digitalWrite(IN1, LOW);
    // Stop motion
    digitalWrite(IN2, LOW);
    
    Serial.println("Car stopped. Relay OFF.");
  } else if (command == "REVERSE") {
    digitalWrite(RELAY_PIN, LOW);  // Energize the relay (Active Low logic)
    digitalWrite(IN1, LOW);
    // Reverse motion
    digitalWrite(IN2, HIGH);
    Serial.println("Car in reverse. Moving backward.");
  } else {
    Serial.println("Invalid command received.");
  }
}
