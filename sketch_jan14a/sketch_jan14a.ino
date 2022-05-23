//Librerias para LCD I2C
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//Init LCD
LiquidCrystal_I2C lcd(0x3F,16,2);
void setup() {
  //Init LCD
//  lcd.begin(16, 2);
  //Mensaje
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print (F("Linea 0"));
  lcd.setCursor(0, 1);
  lcd.print (F("Linea 1"));
}
void loop() {
}
