
int Pin13=13,Pin12=12,Pin11=11,Pin7=7,Pin6=6,Pin5=5;
char RX;

void setup() {
  
  pinMode(Pin5,OUTPUT);pinMode(Pin6,OUTPUT);pinMode(Pin7,OUTPUT);
  pinMode(Pin11,OUTPUT);pinMode(Pin12,OUTPUT),pinMode(Pin13,OUTPUT);
  Serial.begin(9600);
  Serial.print('En espera...'); 
}

void loop() {
  
  if(Serial.available()>0) {
    RX-Serial.read();
    Serial.print('Recibe: '); Serial.print(RX);
  }
  
}
