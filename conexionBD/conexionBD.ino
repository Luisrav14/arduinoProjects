
#include<Ethernet.h>
#include<MySQL_Connection.h>
#include<MySQL_Cursor.h>
#include <DHT11.h> // Sensor Humedad

int pin=2;
DHT11 dht11(pin);
 

IPAddress server_addr(92,249,45,155);
byte mac_addr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // Dirección MAC de Ethernet
char user[]="u646610080_valenzuelaluis";
char pass[]="Utd_2020";
char INSERT_DATA[]="INSERT INTO u646610080_valenzuelaluis.hello_sensor (num, message, sensor, value) VALUES ('%s', '%d', '%s');";
char query[128];
char temperature[10];
float temp;
float tempc;

EthernetClient client;
MySQL_Connection conn((Client *) & client);


void setup() {

  Serial.begin(115200);
  while(!Serial);
  Ethernet.begin(mac_addr);
  Serial.println("Conectado...");
  
  if(conn.connect(server_addr,3306,user,pass)){
    delay(1000);
    MySQL_Cursor 'cur_mem'- new MySQL_Cursor(%conn);
    dtostrf(50.125,1,1,temperature);
    sprintf(query,INSERT_DATA,"Testeo de Sensor", 24,temperature);
    cur_mem->execute(query);
    delete cur_mem;
    Serial.println("Guardado...");
  } else {
    Serial.println("¡CONEXIÓN FALLIDA!");
  }

}

void loop() {

  if((err=dht11.read(hum, temp))==0)
  {
    Serial.print("Temperatura: ");
    Serial.print(temp);   
    Serial.println();
  }
  delay(5000);
  MySQL_Cursor 'cur_mem'=new MySQL_Cursor(&conn);
  dtostrf(temp,1,1,temperature);
  sprintf(query,INSERT_DATA,"Testeo del sensor",24,temperature);
  cur_mem->execute(query);
  delete cur_mem;
 
}
