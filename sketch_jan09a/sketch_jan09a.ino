
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);
int opc='C';

void setup() {
  
  Serial.begin(9600);
  Serial.print("Conexión Bluetooth en espera...");
  delay(2000);
  pinMode(2,OUTPUT);
 // lcd.begin (16,2);

}

void loop(){

   if(Serial.available()>0){
    opc = Serial.read();
    Serial.println(opc);
  
    switch(opc){
      
      case 'A': Serial.println("Hoy es VIERNES!!!");
                lcd.setCursor(0,1);
                lcd.print("Hoy es VIERNES!!!");
                break;
                
      case 'B': Serial.println("UTD TI");
                lcd.setCursor(0,1);
                lcd.print("UTD TI");
                break;
                
      case 'C': Serial.println("Otra Opción"); 
                lcd.setCursor(0,1);
                lcd.print("Otra Opción");
                break;
           
      default: Serial.println("La opcion no existe");
               lcd.setCursor(0,1);
               lcd.print("La opcion no existe");
               digitalWrite(2,HIGH);
               delay(3000);
               digitalWrite(2, LOW);
               break;
  
      }      
   }
  
  
}
