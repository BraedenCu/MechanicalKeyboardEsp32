#include <Keypad.h>
#include <WiFi.h>
#include <LiquidCrystal.h>
//"" makes it search in current dir.
#include "networkInfo.h"

const byte n_rows = 5;
const byte n_cols = 6;


char keys[n_rows][n_cols] = {
  {'~', '1', '2', '3', '4', '5'},
  {'=', 'q', 'w', 'e', 'r', 't'},
  {'-', 'a', 's', 'd', 'f'},
  {';', 'z', 'c', 'v', 'b'},
  {'#', '$', '%'}
};

//start at escape and go down for rows, left for collumns 
byte colPins[n_rows] = {15,2,0,4,16};
byte rowPins[n_cols] = {5,18,19,21,22,23};

Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, n_rows, n_cols);

WiFiServer wifiServer(8000);

const int rs = 21, en = 22, d4 = 23, d5 = 24, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {

  Serial.begin(115200);
  
  //setup the lcds number of collumns and rows
  lcd.begin(16,2);
  lcd.print("Braeden Cullen : 847-767-1210");
  lcd.display();
  
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

  WiFiClient client = wifiServer.available();

  //Serial.println(client.remoteIP());
  while(client) {
    char myKey = myKeypad.getKey();
  
    //reading data from client
    char c = client.read();
    //UPDATE LCD
    //lcd.print(c);
    
    
    if (myKey != NULL) {
      Serial.println(myKey);
      client.print(myKey);
    }
  }
  
}
