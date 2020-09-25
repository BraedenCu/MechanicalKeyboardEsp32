#include "BleKeyboard.h"

const int numRows = 6;
const int numCols = 5;

//row pins
//23,22,tx,rx,21,19
//const int r1=23,r2=22,r3=1,r4=3,r5=21,r6=19;
const int r1=22;
//collumn pins
//32,33,25,26,27
const int c1=32;

char* keys[5][6] = {
  {"esc","1","2","3","4","5"},
  {"tab","q","w","e","r","t"},
  {"CapsLock", "a","s","d","f","g"},
  {"Shift", "z", "x", "c", "v","b"},
  {"ctrl", "win", "alt", "null", "null", "space"}
};

char* getkey(){
  for(int n=0;n<(numCols);n++) {
    digitalWrite(c1, HIGH);
    for (int i=0;i<(numRows);i++) {
      int x = digitalRead(r1);
      if (x==1) {
        x=0;
        return keys[n][i];
      }
      x=0;
    }
    digitalWrite(c1, LOW);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(c1, OUTPUT);
  pinMode(r1, INPUT);
}

void loop() {
  char*x=getkey();
  Serial.println(x);
  
  delay(1000);

}
