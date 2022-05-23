#include <SPI.h>
#include <Ethernet.h>
#include <DHT.h>
#include <DHT_U.h>

// Init Ethernet 

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,101,50); // Arduino IP
char server[] = "92.249.45.201"; // Servidor IP
EthernetClient client;

// Init Sensores

const int analogInPin = A0; 
int sensorValue = 0;
DHT dht(2, DHT11);

void setup() {
  dht.begin();
  Ethernet.begin(mac, ip);
  delay(1000);
  Serial.begin(9600);
}

void loop() {

  String hString = "";
  String tString = "";
  String aString = "";
  
  if (client.connect(server, 80)) { 

  int h = dht.readHumidity();
  hString = h;
  int t = dht.readTemperature();
  tString = t;
  int f = dht.readTemperature(true);
 
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }

  sensorValue = analogRead(analogInPin);
  int n_agua = sensorValue*100/1024+100;
  aString = n_agua;
 
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" ºC ");
  Serial.print(" \t");
  Serial.print("Nivel de Agua:  " ); 
  Serial.print(n_agua); 
  Serial.println("%");

 String stemp = "temp=" + tString;
 String shum = "&hum="+ hString;
 String sagua = "&nagua=" + aString;
 String params = stemp + shum + sagua;
 

  Serial.println("---------- Guardando Información... -------------");
  client.print("GET http://rodriguezchristian.utdgrupoti.com/mongo_luis/smart_pot.php?" + params);
  client.println(" HTTP/1.0");     
  client.println("User-Agent: Arduino 1.0");     
  client.println();     
  client.stop();     
  client.flush();

 delay(2000);
  
  } else {
    Serial.println("Falla en la conexion");
  }

  client.stop();
  client.flush();
  delay(100);
}
