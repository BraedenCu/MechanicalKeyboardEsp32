#include <Keypad.h>
#include <WiFi.h>
#include <LiquidCrystal.h>
#include "networkInfo.h"

const byte n_rows = 5;
const byte n_cols = 6;

//using hexidecimal because chars are for noobs
char keys[n_rows][n_cols] = {
  {0x1B, 0x31, 0x32, 0x33, 0x34, 0x35},
  {0x9, 0x51, 0x58, 0x45, 0x52, 0x54},
  {0x14, 0x41, 0x53, 0x44, 0x46},
  {0x10, 0x5A, 0x43, 0x56, 0x42},
  {0x11, 0x5B, 0x12, 0x20}
};

//start at escape and go down for rows, left for collumns 
byte colPins[n_rows] = {15,2,0,4,16};
byte rowPins[n_cols] = {5,18,19,21,22,23};
Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, n_rows, n_cols);

WiFiServer wifiServer(8000);

const int NUMPIXELS = 60;
const int rgbpin = 33;
const int colorSaturation = 128;
//NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(NUMPIXELS, rbgpin);

//rs,en,d4,d5,d6,d7
//LiquidCrystal lcd(34,35,32,25,26,27);

void setup() {

  //strip.Begin();
  //strip.Show();
 
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) { 
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected");
  Serial.println(WiFi.localIP());

  wifiServer.begin();
}

void loop() {

  //strip.SetPixelColor(0, red);
  //strip.Show()
  
  //lcd.print(“hello, world!”);
  
  WiFiClient client = wifiServer.available();

  //Serial.println(client.remoteIP());
  while(client) {
    char myKey = myKeypad.getKey();
  
    //reading data from client
    char c = client.read();
    
    if (myKey != NULL) {
      Serial.println(myKey);
      client.print(myKey);
    }
  }
  
}
