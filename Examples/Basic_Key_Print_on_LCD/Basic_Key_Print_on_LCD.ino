#include <Wire.h>
#include "Keypad_I2C.h"
#include "LCD_I2C.h"

#define I2CADDR 0x27

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','*'},
  {'4','5','6','/'},
  {'7','8','9','-'},
  {'.','0','=','+'}
};
// Pin connections on MCP23017 for keys
 byte rowPins[] = {3,2,1,0}; //connections of the row pinouts of the keypad
 byte colPins[] = {4,5,6,7}; //connections of the column pinouts of the keypad
 
Keypad_I2C keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS,I2CADDR);
LCD_I2C lcd(I2CADDR);

void setup() {
  Serial.begin(9600);
  keypad.begin( );  

  lcd.begin(16, 2);
  lcd.display();
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("Extended Nano ");
  lcd.setCursor(0,1); 
  lcd.print("Key : ");
}


void loop() {
   char key = keypad.getKey();
  
  if (key){
  	  lcd.setCursor(6,1); lcd.print(key); 
  
    //Serial.println(key);

  }
}
