
#include <Wire.h>
#include <LCDI2C.h>


LiquidCrystal_I2C lcd(0x3F,16,2);

void setup() {
  
  lcd.init();
  Serial.begin(9600);
  Serial.print("Conexión Bluetooth en espera...");
  delay(2000);
  pinMode(2,OUTPUT);  

}

void loop() {

  

}
