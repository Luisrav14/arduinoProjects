void setup() {
    
    Serial.begin(9600);
}

void loop() {
  
 if(Serial.available() > 0){
      state = Serial.read();
  } 
  
// Esta parte del código es para solo 1 Carácter o Unidad. 
  
 if (state == '0') {
    Serial.println("LED: off");
 }
 
 // De lo contrario si el estado es 1 ese sería Encendido “ON” else
 
 if (state == '1') {
     Serial.println("LED: on");
 }

}
