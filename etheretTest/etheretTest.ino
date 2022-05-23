#include <SPI.h> 
#include <Ethernet.h>   

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  

// MAC de la tarjeta ethernet shield  
IPAddress ip(192,168,101,50); 

//Dirección del ethernet Shield 
char server[] = "192.168.101.47";  //Dirección de la computadora. 

EthernetClient client;   
void setup() {   
  Ethernet.begin(mac, ip); 
  // Inicializa el Ethernet Shield   
  delay(1000);    
  Serial.begin(9600); 
 }  
 
void loop() {   
  if (client.connect(server, 80)) {   
     Serial.println("Conectado");   
  } else {     
     Serial.println("Falla en la conexion");  
  }    
  client.stop();  
  client.flush();   
  delay(100); 
  }
