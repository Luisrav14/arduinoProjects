
int PINs1rojo=13,PINs1Ama=12,PINs1verde=11;
int PINs2rojo=7,PINs2Ama=6,PINs2verde=5;  

void setup() {
  pinMode(PINs1rojo,OUTPUT);pinMode(PINs1Ama,OUTPUT);pinMode(PINs1verde,OUTPUT);
  pinMode(PINs2rojo,OUTPUT);pinMode(PINs2Ama,OUTPUT);pinMode(PINs2verde,OUTPUT);
}

void loop() {
  
  digitalWrite(PINs1rojo,HIGH);
  digitalWrite(PINs2verde,HIGH);  
  delay(5000);
  digitalWrite(PINs2verde,LOW);
  delay(500);
  digitalWrite(PINs2verde,HIGH);  
  delay(500);
  digitalWrite(PINs2verde,LOW);  
  delay(500);
  digitalWrite(PINs2verde,HIGH);  
  delay(500);
  digitalWrite(PINs2verde,LOW);
  delay(500);
  digitalWrite(PINs2verde,HIGH);  
  delay(500);
  digitalWrite(PINs2verde,LOW);
  digitalWrite(PINs2Ama,HIGH);
  delay(1500);
  digitalWrite(PINs2Ama,LOW);
  digitalWrite(PINs2rojo,HIGH);
  digitalWrite(PINs1rojo,LOW);
  digitalWrite(PINs1verde,HIGH);
  delay(5000);
  digitalWrite(PINs1verde,LOW);
  delay(500);
  digitalWrite(PINs1verde,HIGH);  
  delay(500);
  digitalWrite(PINs1verde,LOW);  
  delay(500);
  digitalWrite(PINs1verde,HIGH);  
  delay(500);
  digitalWrite(PINs1verde,LOW);
  delay(500);
  digitalWrite(PINs1verde,HIGH);  
  delay(500);
  digitalWrite(PINs1verde,LOW);
  digitalWrite(PINs1Ama,HIGH);
  delay(1500);
  digitalWrite(PINs1Ama,LOW);
  digitalWrite(PINs1rojo,HIGH);
  digitalWrite(PINs2rojo,LOW);
  digitalWrite(PINs2verde,HIGH);

}
