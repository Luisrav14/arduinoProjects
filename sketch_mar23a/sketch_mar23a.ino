#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

String ssid     = "INFINITUM";
String password = "172776";

byte cont = 0;
byte max_intentos = 50;

const MongoClient = require('mongodb').MongoClient;
const uri = "mongodb+srv://Admin:12345@cluster0.7tngt.mongodb.net/Arduino.esp8266?retryWrites=true&w=majority";
const client = new MongoClient(uri, { useNewUrlParser: true, useUnifiedTopology: true });

void setup() {
  // Inicia Serial
  Serial.begin(115200);
  Serial.println("\n");

  // Conexión WIFI
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED and cont < max_intentos) { //Cuenta hasta 50 si no se puede conectar lo cancela
    cont++;
    delay(500);
    Serial.print(".");
  }

Serial.println("");

  if (cont < max_intentos) {  //Si se conectó      
      Serial.println("****************");
      Serial.print("Conectado a la red WiFi: ");
      Serial.println(WiFi.SSID());
      Serial.print("IP: ");
      Serial.println(WiFi.localIP());
      Serial.print("macAdress: ");
      Serial.println(WiFi.macAddress());
      Serial.println("***************");
      client.connect(err => {
      const collection = client.db("test").collection("devices");
      // perform actions on the collection object
      client.close();
      });
  }
  else { //No se conectó
      Serial.println("------------------------------------");
      Serial.println("Error de conexion");
      Serial.println("------------------------------------");
  }
}

void loop() {
 
}
