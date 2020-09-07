#include <Keypad.h>
 
const byte n_rows = 4;
const byte n_cols = 6;
 
char keys[n_rows][n_cols] = {
  {'~','1','2','3', '4', '5'},
  {'=','q','w','e', 'r', 't'},
  {'-', 'a', 's', 'd', 'f'},
  {';','z','x','c', 'v', 'b'}
};
 
byte colPins[n_rows] = {5,18,19,21};
byte rowPins[n_cols] = {15, 2, 0, 4, 16, 17};
 
Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, n_rows, n_cols); 
 
void setup(){
  Serial.begin(115200);
}
 
void loop(){
  char myKey = myKeypad.getKey();
 
  if (myKey != NULL){
    Serial.print("Key pressed: ");
    Serial.println(myKey);
  }
}
