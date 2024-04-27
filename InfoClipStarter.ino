// InfoClip Starter Code
// Zane Cochran
// 13 APR 2024

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// Setup
const char* ssid = "EZConnect";
const char* password = "HackBerryPlay";
String apiUrl = "https://www.thecocktaildb.com/api/json/v1/1/random.php?"; // ***UPDATE THIS***

DynamicJsonDocument doc(1024);

// Information
// String sunrise = "";
// String sunset = "";

String drinks = "";
String inst = "";
String ingredients[15];
String quantity[15];
int yOffset = 0;

// State Machine
int mode = -1;
int lastMode = -1;

void setup() {
  Serial.begin(115200);
  delay(1000);

  wifiConnect();
  wifiRequest();
  initDisplay();
  initButtons();
}

void loop() {
  checkButtons();
  checkSleep();

  switch(mode){
    case -1: showIntro(); break;
    case 0: showSleep(); break;
    case 1: showDrinks(); break;
  //  case 2: showInstructions(); break;
  }
}
