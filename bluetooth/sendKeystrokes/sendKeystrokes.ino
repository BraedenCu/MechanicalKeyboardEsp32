#include "BleKeyboard.h"

BleKeyboard bleKeyboard;

int numRows = 6;
int numCols = 5;

//row pins
int r1=15,r2=2,r3=0,r4=4,r5=16,r6=17;
//collumn pins
int c1=34,c2=35,c3=32,c4=33,c5=25;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  pinMode(0, OUTPUT);
  pinMode(4, INPUT);
  
  digitalWrite(0, HIGH);
  
  bleKeyboard.begin();
}

void loop() {
  Serial.println(".");
  
  if(bleKeyboard.isConnected()) {
    int test = digitalRead(4);
    if (test == 0) {
      Serial.println("yeah");
      bleKeyboard.print("t");
    }

  }
  
  //bleKeyboard.releaseAll();
  delay(5000);
}

char getPressedKey(int coll) {
  
}
