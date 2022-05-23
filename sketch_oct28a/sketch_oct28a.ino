
int Opc='C';
int pin13=13,pin12=12,pin11=11,pin7=7,pin6=6,pin5=5;

void setup() {
  
   Serial.begin(9600);
   pinMode(pin13,OUTPUT);pinMode(pin12,OUTPUT);pinMode(pin11,OUTPUT);
   pinMode(pin7,OUTPUT);pinMode(pin6,OUTPUT);pinMode(pin5,OUTPUT);
   Serial.print("   Conexion Bluetooth en espera.. ");
   delay(2000);
   
}

void loop() {

     if(Serial.available()>0){
         Opc=Serial.read();
         Serial.println(" OPC: ");Serial.print(Opc);
         
         switch(Opc){
          
          case '1':
            Serial.println("OPCION D");
            digitalWrite(pin13,HIGH);
            break; 
            
          case '1':
          
            break;
            
          case '1':
             
            break;
          case '1':
             
            break;

          case '1':
             
            break;
            
          default: 
            Serial.printf("Opcion no existe..");       
            break;
        }
      }
}
