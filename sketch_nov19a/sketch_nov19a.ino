
#include LiquidCrystal.h
#include<SPI.h>
#include<MFRC522.h>
#define RST_PIN 9
#define SS_PIN 10
MFRC522 mfrc522(SS_PIN,RST_PIN);
//Set the pins on the I2C chip used for LCD connections
//ADDR,EN,R/W,RS,D4,D5,D6,D7
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7); // 0x27 is the default I2C bus address of the backpack-see article
void setup()
{  Serial.begin(9600);
   SPI.begin(); 
   mfrc522.PCD_Init();
   // Set off LCD module
   lcd.begin (16,2); // 16 x 2 LCD module
   lcd.setBacklightPin(3,POSITIVE); // BL, BL_POL
   lcd.setBacklight(HIGH);
   lcd.setCursor(0,0);
   lcd.print("Lectura del Rfid");
  // lcd.setCursor(0,1);
  // lcd.print("Hola Mundo");   
}
void loop()
{
  int comp=0;// Variable utilizada para comparacion, si el resultado es cero, es que la comparacion es verdadera
byte cad[50]="5B 2B 39 1F";// valor que contiene la tarjeta..
float acu=0;
  // Revisamos si hay nuevas tarjetas  presentes
  if ( mfrc522.PICC_IsNewCardPresent()) 
        {  
      //Seleccionamos una tarjeta
            
            if ( mfrc522.PICC_ReadCardSerial()) 
            {
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
               Serial.println("       Correcto!!");
               lcd.setCursor(0,1);
               lcd.print("Correcto!!");delay(3000);
               lcd.setCursor(0,1);
               lcd.print("          ");delay(1000);                
              } else {
                Serial.println("       inCorrecto!!!!!");  
                lcd.setCursor(0,1);
                lcd.print("inCorrecto!!");delay(3000);
                lcd.setCursor(0,1);
                lcd.print("            ");delay(1000);
                                 
                }                    
            } 
}
