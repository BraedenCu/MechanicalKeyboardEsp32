#include "BleKeyboard.h"
//6,5
const int numRows = 2;
const int numCols = 2;

//row pins
//23,22,tx,rx,21,19
//const int r1=23,r2=22,r3=1,r4=3,r5=21,r6=19;
const int r1=22, r2=23, r3=1, r4=2, r5=3, r6=4;
//collumn pins
//32,33,25,26,27
const int c1=32, c2=33, c3=5, c4=6, c5=7;

int rowpins[6] = {r1,r2,r3,r4,r5,r6};
int colpins[5] = {c1,c2,c3,c4,c5};

char* keys[5][6] = {
  {"esc","1","2","3","4","5"},
  {"tab","q","w","e","r","t"},
  {"CapsLock", "a","s","d","f","g"},
  {"Shift", "z", "x", "c", "v","b"},
  {"ctrl", "win", "alt", "null", "null", "space"}
};

char* getkey(){
  for(int n=0;n<(numCols);n++) {
    //digitalWrite(colpins[n], HIGH);
    for (int i=0;i<(numRows);i++) {
      digitalWrite(colpins[n], HIGH);
      int x=0;
      x = digitalRead(rowpins[i]);
      if (x==1) {
        Serial.println(i);
        Serial.println(n);
        return keys[n][i];
      }
      digitalWrite(colpins[n], LOW);
    }
    //digitalWrite(colpins[n], LOW);
  }
  return "bruh";
}

void setup() {
  Serial.begin(115200);
  pinMode(c1, OUTPUT);
  pinMode(c2, OUTPUT);
  //pinMode(c3, OUTPUT);
  //pinMode(c4, OUTPUT);
  //pinMode(c5, OUTPUT);
  pinMode(r1, INPUT);
  pinMode(r2, INPUT);
  //pinMode(r3, INPUT);
  //pinMode(r4, INPUT);
  //pinMode(r5, INPUT);
  //pinMode(r6, INPUT);
}

void loop() {
  char*x=getkey();
  Serial.println(x);
  delay(1000);

}
