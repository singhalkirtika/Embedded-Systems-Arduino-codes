// include the library code:
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int ledPin = 13;

const int ldrPin = A0;

void setup() { //initialise for at least 2s
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("INITIALISING");
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
}
void loop()
{
 int sensorValue = analogRead(A0);
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("LIGHT LEVEL:");
 lcd.print(sensorValue);
 lcd.setCursor(0, 1);
  
if (sensorValue <= 200) {

digitalWrite(ledPin, HIGH);

Serial.print("Its DARK, Turn on the LED : ");

Serial.println(sensorValue);

} else {

digitalWrite(ledPin, LOW);

Serial.print("Its BRIGHT, Turn off the LED : ");

Serial.println(sensorValue);

}
}
