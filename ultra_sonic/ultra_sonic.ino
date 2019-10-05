#include <Arduino.h>
#include <LiquidCrystal.h>

#define trigger A4
#define echo A5

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float time = 0, distance = 0;

void setup()
{
Serial.begin(9600);
lcd.begin(16, 2);
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
lcd.print(" Ultra sonic");
lcd.setCursor(0, 1);
lcd.print("Distance Meter");
delay(2000);
lcd.clear();
}

void loop()
{
lcd.clear();
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
delayMicroseconds(2);
time = pulseIn(echo, HIGH);
distance = time * 340 / 20000;
Serial.println(distance);
lcd.clear();
lcd.print("Distance:");
lcd.print(distance);
lcd.print("cm");
lcd.setCursor(0, 1);
lcd.print("Distance:");
lcd.print(distance / 100);
lcd.print("m");
delay(1000);
}
