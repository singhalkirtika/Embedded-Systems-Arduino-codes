#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 1, 0);

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("KEYPAD LCD TEST"); 
}
  
void loop(){
  char customKey = customKeypad.getKey();
  lcd.setCursor(0, 1);
  
  if (customKey){
    //lcd.print("KEY= ");  
    lcd.setCursor(9, 1);  
    //lcd.print(customKey);
   Serial.println(customKey); 
  }
}
