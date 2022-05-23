#include <ESP8266WiFi.h>
#include "Wire.h" // For I2C
#include "LCD.h" // For LCD
#include "LiquidCrystal_I2C.h"
String ssid     = "Ubee6122";
String password = "1409100580CERPP";

//LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7);
byte cont = 0;
byte max_intentos = 20;

void setup() {
  // Inicia Serial
  Serial.begin(115200);
  Serial.println("\n");
  //LCD
  // initialize LCD
   lcd.begin (16,2); // 16 x 2 LCD module
   lcd.setBacklightPin(3,POSITIVE); // BL, BL_POL
   lcd.setBacklight(HIGH);
   lcd.clear();
lcd.setCursor(0, 0);lcd.print("Espera!!!");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED and cont < max_intentos) { //Cuenta hasta 50 si no se puede conectar lo cancela
    cont++;
    delay(500);
    Serial.print(".");

  }

Serial.println("");
delay(1000);
lcd.clear();

  if (cont < max_intentos) {  //Si se conectó      
      Serial.println("****************");
      Serial.print("Conectado a la red WiFi: ");

  
      Serial.println(WiFi.SSID());
      Serial.print("IP: ");Serial.println(WiFi.localIP());
  
      
      Serial.print("macAdress: ");
      Serial.println(WiFi.macAddress());
      Serial.println("***************");

       lcd.setCursor(1, 1);
      lcd.print("Conectado");
  }
  else { //No se conectó
      Serial.println("------------------------------------");
      Serial.println("Error de conexion");
      Serial.println("------------------------------------");
      
  }
}

void loop() {      

  if(WiFi.status() == WL_CONNECTED){
   lcd.setCursor(1, 1);
  lcd.print("Conectado");
    }else{
  lcd.setCursor(1, 1);
  lcd.print("SIN conexion");
    }

}
