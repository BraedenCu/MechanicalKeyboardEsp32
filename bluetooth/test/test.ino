#include "BleKeyboard.h"

BleKeyboard bleKeyboard;

const int numRows = 6;
const int numCols = 5;

//row pins
//23,22,tx,rx,21,19
//const int r1=23,r2=22,r3=1,r4=3,r5=21,r6=19;
const int r1=23,r2=0,r3=0,r4=0,r5=0,r6=0;
//collumn pins
//32,33,25,26,27
const int c1=32,c2=33,c3=25,c4=26,c5=27;

const int rowpins[numRows] = {r1,r2,r3,r4,r5,r6};
const int colpins[numCols] = {c1,c2,c3,c4,c5};

char* keys[numCols][numRows] = {
  {"esc","1","2","3","4","5"},
  {"tab","q","w","e","r","t"},
  {"CapsLock", "a","s","d","f","g"},
  {"Shift", "z", "x", "c", "v","b"},
  {"ctrl", "win", "alt", "null", "null", "space"}
};

char* getkey() {
  //iterate over collumns
  for (int n = 0; n<numCols; n++) {
    //set that collum to high
    pinMode(colpins[n], HIGH);
    //iterate through rows
    for (int i = 0; i<numRows; i++) {
      int x = 0;
      Serial.println(digitalRead(rowpins[i]));
      if (x==HIGH) {
        Serial.println("HIGH");
      }
    }
    //set that collum back to low
    pinMode(colpins[n], LOW); 
  }
}


void setup() {
  Serial.begin(115200);
  pinMode(rowpins[0], INPUT);
  pinMode(rowpins[1], INPUT);
  pinMode(rowpins[2], INPUT);
  pinMode(rowpins[3], INPUT);
  pinMode(rowpins[4], INPUT);
  pinMode(rowpins[5], INPUT);

  pinMode(colpins[0], OUTPUT);
  pinMode(colpins[2], OUTPUT);
  pinMode(colpins[3], OUTPUT);
  pinMode(colpins[4], OUTPUT);
 
}

void loop() {
  char*key = getkey();
  
  delay(1000);
  

  bleKeyboard.releaseAll();
}
