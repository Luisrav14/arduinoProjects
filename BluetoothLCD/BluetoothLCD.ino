
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include<SPI.h>
#include<MFRC522.h>

int Opc='C';
int pin8 = 2;
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7);

void setup(){  
  Serial.begin(9600);
   SPI.begin(); 
   lcd.begin (16,2);
   lcd.setBacklightPin(3,POSITIVE);
   lcd.setBacklight(HIGH);
   lcd.setCursor(0,0);
   lcd.print("");

}

void loop(){
    if(Serial.available()>0){
      
    Opc = Serial.read();
    Serial.println(Opc);

    switch(Opc){
      case 'A': lcd.setCursor(4,0); lcd.print("Boton 1"); break;
      case 'B': lcd.setCursor(4,0); lcd.print("Boton 2"); break;
      case 'C': lcd.setCursor(4,0); lcd.print("Boton 3");  break;
      
      default: 
      digitalWrite(pin8,HIGH); delay(2000); digitalWrite(pin8,LOW);
      break;
      
      
      }
    }   
  }
