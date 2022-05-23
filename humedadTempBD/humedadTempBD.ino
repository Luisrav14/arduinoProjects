#include <DHT11.h>
#include <Ethernet.h>
#include <SPI.h>


dht11 DHT;
#define DHT11_PIN 7

// Configuracion del Ethernet Shield
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFF, 0xEE}; // Direccion MAC
byte ip[] = { 192,168,101,50 }; // Direccion IP del Arduino
byte server[] = { 92,249,45,155 }; // Direccion IP del servidor
EthernetClient client; 

void setup(){
  Serial.begin(9600);
  Serial.println("DHT TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT11LIB_VERSION);
  Serial.println();
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
  Ethernet.begin(mac, ip); // Inicializamos el Ethernet Shield
}

void loop(){
  int chk;
  int temp;
  int hum;
  
  Serial.print("DHT11, \t");
  chk = DHT.read(DHT11_PIN);    // READ DATA
  switch (chk){
    case DHTLIB_OK:  
                Serial.print("OK,\t"); 
                break;
    case DHTLIB_ERROR_CHECKSUM: 
                Serial.print("Checksum error,\t"); 
                break;
    case DHTLIB_ERROR_TIMEOUT: 
                Serial.print("Time out error,\t"); 
                break;
    default: 
                Serial.print("Unknown error,\t"); 
                break;
  }
 // DISPLAT DATA
  hum = DHT.humidity,1;
  Serial.print(",\t");
  temp = DHT.temperature,1;
  Serial.println(temp);
  Serial.println(hum);

  // Proceso de envio de muestras al servidor
  Serial.println("Connecting...");
  if (client.connect(server, 80)>0) {  // Conexion con el servidor
    client.print("GET /arduino/controller/index.php?temp="); // Enviamos los datos por GET
    client.print(temp);
    client.print("&hum=");
    client.print(hum);
    client.println(" HTTP/1.0");
    client.println("User-Agent: Arduino 1.0");
    client.println();
    Serial.println("Conectado");
  } else {
    Serial.println("Fallo en la conexion");
  }
  if (!client.connected()) {
    Serial.println("Disconnected!");
  }
 client.stop();
  client.flush();
  delay(1000); // Espero un minuto antes de tomar otra muestra
}
