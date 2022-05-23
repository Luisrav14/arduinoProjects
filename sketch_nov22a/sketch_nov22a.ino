
#include <LiquidCrystal.h>
#include<SPI.h>
#include<MFRC522.h>
#include <Servo.h>

#define RST_PIN 9
#define SS_PIN 10

int pos = 0;

Servo myservo;
MFRC522 mfrc522(SS_PIN,RST_PIN);
LiquidCrystal lcd (7,6,5,4,3,2);


void setup() {  
   Serial.begin(9600);
   SPI.begin(); 
   mfrc522.PCD_Init();
   
   // Set off LCD module
   
   lcd.begin (16,2); // 16 x 2 LCD module
   lcd.setCursor(0,0);
   lcd.print("Lectura del Rfid");
   myservo.attach(8); // Servo a pin 8
   myservo.write(0);
}

void loop(){
  
  int comp=0;                   // Variable utilizada para comparacion, si el resultado es cero, es que la comparacion es verdadera
  byte cad[50]="5B 2B 39 1F";   // valor que contiene la tarjeta..
  float acu=0;
  
  if ( mfrc522.PICC_IsNewCardPresent()){   
             
      if ( mfrc522.PICC_ReadCardSerial()){       
            // Enviamos serialemente su UID
            Serial.print("Card UID:");
            
            for (byte i = 0; i < mfrc522.uid.size; i++) {
                Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                Serial.print(mfrc522.uid.uidByte[i], HEX);
                comp=strcmp(mfrc522.uid.uidByte[i],cad[i]);
                comp=comp+acu;
            }                 
        mfrc522.PICC_HaltA();         
      }
      if(comp==0){
                
        Serial.println("Acceso Concedido!!!");
        lcd.setCursor(0,1);
        lcd.print("Acceso Concedido!!!");delay(3000);

        digitalWrite(1, HIGH);
        delay(200);
        digitalWrite(1, LOW);
        delay(200);
                        
        for (pos = 0; pos <= 90; pos += 1) {  // goes from 0 degrees to 180 degrees      
            myservo.write(120);                // tell servo to go to position in variable 'pos'
            delay(1000);                        // waits 15ms for the servo to reach the position
        }

        for (pos = 120; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
            myservo.write(pos);              // tell servo to go to position in variable 'pos'
            delay(1000);                       // waits 15ms for the servo to reach the position
        }
        
        lcd.clear();
        lcd.print("Lectura del Rfid");
                  
        } else {
          Serial.println("Acceso Denegado!!!");
          lcd.setCursor(0,1);
          lcd.print("Acceso Denegado!!!");delay(3000);
          lcd.setCursor(0,1);
          digitalWrite(1, HIGH);
          delay(500);
          digitalWrite(1, LOW);
          delay(500);
          lcd.print("Acceso Denegado!!!");delay(1000);
          lcd.clear();
          lcd.print("Lectura del Rfid");
        }
  }

}
