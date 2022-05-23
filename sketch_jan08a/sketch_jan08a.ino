
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);
int Opc='C';
int pin13 = 13;

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(pin13,OUTPUT);
  Serial.print("Conexión Bluetooth en espera");
  delay(2000);
}

void loop() {
  
  if(Serial.available()>0){
    Opc = Serial.read();
    //Serial.println("OPC:"); Serial.print(Opc);

    switch(Opc){
      
      case 'A': Serial.println("Hoy es VIERNES!!!"); 
                break;
                
      case 'B': Serial.println("UTD TI 4EVER"); 
                break;
                
      case 'C': Serial.println("Otra Opción"); 
                break;
           
      default: Serial.println("La opcion no existe");
               digitalWrite(pin13,HIGH);
               delay(3000);
               digitalWrite(pin13, LOW);
               break;
  
      }      
   }    
}
