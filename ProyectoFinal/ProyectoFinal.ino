#include <Wire.h>
#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd (7,6,5,4,3,2);

int lowerThreshold = 310;
int upperThreshold = 510;
int val = 0;
int ledRojo = 12;
int ledVerde = 11;
int ledAzul= 10;
int pos;
int Opc='C';

#define sensorPower 7
#define sensorPin A0

Servo myservo;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2); 
  pinMode(sensorPower, OUTPUT);
  digitalWrite(sensorPower, LOW);

  myservo.attach(9);
  myservo.write(45);

  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);

  Serial.print("Conexión Bluetooth en espera");
  delay(2000);
}

void loop() {
  int level = readSensor();

  if(Serial.available()>0){
    Opc = Serial.read();
    Serial.println("OPC:"); Serial.print(Opc);

    switch(Opc){
      case 'A': 
      myservo.write(0);
      break;
       
      case 'B':
      myservo.write(0);
      break;
      
      default: Serial.println("OPCION NO VÁLIDA"); break;
         
      }
    }

  if (level == 0) {
    Serial.println(" NIVEL DE AGUA: Vacío");
    lcd.setCursor(0,0);
    lcd.print(" NIVEL DE AGUA: ");
    lcd.setCursor(0,1);
    lcd.print("     VACIO      ");

   while(level == 0) {
     analogWrite(ledRojo, 255);
     analogWrite(ledVerde, 0);
     analogWrite(ledAzul, 0);
     delay(500);
     analogWrite(ledRojo, 0);
     analogWrite(ledVerde, 0);
     analogWrite(ledAzul, 0);
     delay(500);
    }
    
  } else if (level > 0 && level <= lowerThreshold) {
    Serial.println("NIVEL DE AGUA: BAJO");
    lcd.setCursor(0,0);
    lcd.print(" NIVEL DE AGUA: ");
    lcd.setCursor(0,1);
    lcd.print("      BAJO      ");

    analogWrite(ledRojo, 255);
    analogWrite(ledVerde, 0);
    analogWrite(ledAzul, 0);
    
  } else if (level > lowerThreshold && level <= upperThreshold) {
    Serial.println("NIVEL DE AGUA: MEDIO");
    lcd.setCursor(0,0);
    lcd.print(" NIVEL DE AGUA: ");
    lcd.setCursor(0,1);
    lcd.print("     MEDIO     ");

    analogWrite(ledRojo, 255);
    analogWrite(ledVerde, 255);
    analogWrite(ledAzul, 0);
    
  } else if (level > upperThreshold) {
    Serial.println("NIVEL DE AGUA: ALTO");
    lcd.setCursor(0,0);
    lcd.print(" NIVEL DE AGUA: ");
    lcd.setCursor(0,1);
    lcd.print("     LLENO     ");

    analogWrite(ledRojo, 0);
    analogWrite(ledVerde, 255);
    analogWrite(ledAzul, 0);
  }
}


int readSensor() {
  digitalWrite(sensorPower, HIGH);
  delay(10);
  val = analogRead(sensorPin);
  digitalWrite(sensorPower, LOW);
  return val;
}
