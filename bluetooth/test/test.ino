#include "BleKeyboard.h"

BleKeyboard bleKeyboard;

const int numRows = 6;
const int numCols = 5;

//row pins
const int r1=23,r2=33,r3=39,r4=34,r5=35,r6=32;
//collumn pins
const int c1=22,c2=25,c3=26,c4=27,c5=14;

const int rowpins[6] = {r1,r2,r3,r4,r5,r6};
const int colpins[5] = {c1,c2,c3,c4,c5};

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
      if (digitalRead(rowpins[i])==1) {
        Serial.println(keys[n][i]);
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
  pinMode(colpins[5], OUTPUT); 
}

void loop() {
  char*key = getkey();
  
  delay(1000);
  
  //int test2 = digitalRead(16);
  //if (test == 1) {
    //Serial.println("yeah");
  //}
  //if (test2 == 1) {
    //Serial.println("nay");
  //}


  //bleKeyboard.releaseAll();
}
