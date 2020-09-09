#include <Keypad.h>
#include <WiFi.h>

const byte n_rows = 4;
const byte n_cols = 6;

const char* ssid = "lake-cullie";
const char* password = "cullen1201";

char keys[n_rows][n_cols] = {
  {'~', '1', '2', '3', '4', '5'},
  {'=', 'q', 'w', 'e', 'r', 't'},
  {'-', 'a', 's', 'd', 'f'},
  {';', 'z', 'c', 'v', 'b'}
};

byte colPins[n_rows] = {15, 2, 0, 4};
byte rowPins[n_cols] = {16, 17, 5, 18, 19, 21};

Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, n_rows, n_cols);

WiFiServer wifiServer(8000);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  do {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  while (WiFi.status() != WL_CONNECTED);

  Serial.println("Connected");
  Serial.println(WiFi.localIP());

  wifiServer.begin();
}


void loop() {

  WiFiClient client = wifiServer.available();

  //Serial.println(client.remoteIP());
  
  while (client.connected()) {
    char myKey = myKeypad.getKey();
    //reading data from client
    char c = client.read();
    //Serial.println(c);
    Serial.println(myKey);
    //sending data to client
    if (myKey != NULL) {
      Serial.println(myKey);
      client.print(myKey);
  }
  
  }
  //disconnected
  client.stop();
  
 
}
