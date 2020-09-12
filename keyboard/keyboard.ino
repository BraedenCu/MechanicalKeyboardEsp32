#include <Keypad.h>
#include <WiFi.h>
#include <LiquidCrystal.h>

const byte n_rows = 5;
const byte n_cols = 6;

const char* ssid = "lake-cullie";
const char* password = "cullen1201";

char keys[n_rows][n_cols] = {
  {'~', '1', '2', '3', '4', '5'},
  {'=', 'q', 'w', 'e', 'r', 't'},
  {'-', 'a', 's', 'd', 'f'},
  {';', 'z', 'c', 'v', 'b'},
  {'#', '$', '%'}
};

byte colPins[n_rows] = {7, 8, 15, 2, 0};
byte rowPins[n_cols] = {4, 16, 17, 5, 18, 19};

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
    lcd.print(c);
    
    
    if (myKey != NULL) {
      Serial.println(myKey);
      client.print(myKey);
    }
  }
  
}
