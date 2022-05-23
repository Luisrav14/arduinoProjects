int Opc='C';
int pin13 = 13,pin12 = 12,pin11 = 11;
int pin7 = 7,pin6 = 6,pin5 = 5;
void setup() {
  Serial.begin(9600);
  pinMode(pin13,OUTPUT);pinMode(pin12,OUTPUT);pinMode(pin11,OUTPUT);
  pinMode(pin7,OUTPUT);pinMode(pin6,OUTPUT);pinMode(pin5,OUTPUT);
  Serial.print("Conexión Bluetooth en espera");
  delay(2000);

}

void loop() {
  if(Serial.available()>0){
    Opc = Serial.read();
    Serial.println("OPC:"); Serial.print(Opc);

    switch(Opc){
      case 'P': digitalWrite(pin13,HIGH); break;
      case 'A': digitalWrite(pin13,LOW); break;
      case 'D': 
      
      digitalWrite(pin13,HIGH); delay(200);
      digitalWrite(pin12,HIGH); digitalWrite(pin13,LOW); delay(200);
      digitalWrite(pin12,LOW);

       digitalWrite(pin11,HIGH); delay(200);
      digitalWrite(pin7,HIGH); digitalWrite(pin11,LOW); delay(200);
      digitalWrite(pin7,LOW);

      digitalWrite(pin6,HIGH); delay(200);
      digitalWrite(pin5,HIGH); digitalWrite(pin6,LOW); delay(200);
      digitalWrite(pin5,LOW);

      digitalWrite(pin5,HIGH); delay(200);
      digitalWrite(pin6,HIGH); digitalWrite(pin5,LOW); delay(200);
      digitalWrite(pin6,LOW);

      digitalWrite(pin7,HIGH); delay(200);
      digitalWrite(pin11,HIGH); digitalWrite(pin7,LOW); delay(200);
      digitalWrite(pin11,LOW);

           digitalWrite(pin12,HIGH); delay(200);
      digitalWrite(pin13,HIGH); digitalWrite(pin12,LOW); delay(200);
      digitalWrite(pin13,LOW);
      
      
      
      break;
      case 'S': break;
      default: Serial.print("La opcion no existe"); break;
      
      
      
      }
    }
}
