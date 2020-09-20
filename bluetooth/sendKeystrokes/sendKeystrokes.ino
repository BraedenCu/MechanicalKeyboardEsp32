#include "BleKeyboard.h"

BleKeyboard bleKeyboard;

int numRows = 6;
int numCols = 5;

//row pins
int r1=15, r2=2, r3=0, r4=4, r5=16, r6=17;
//collumn pins
int c1=34,c2=35,c3=32,c4=33,c5=25;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  pinMode(0, OUTPUT);
  pinMode(4, INPUT);
  
  bleKeyboard.begin();
}

void loop() {
  int test = digitalRead(4);
  
  Serial.println(test);

  digitalWrite(0, HIGH);
  
  if(bleKeyboard.isConnected()) {
    bleKeyboard.print("Hello world");

    delay(1000);

    bleKeyboard.write(KEY_RETURN);

    delay(1000);

    bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);

    delay(1000);

    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_DELETE);
    delay(100);
  

  }
  bleKeyboard.releaseAll();
  delay(5000);
}
