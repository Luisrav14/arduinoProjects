#include <SPI.h>
#include <Ethernet.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

IPAddress server_addr(92,249,45,155);
byte mac_addr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
char user[] = "u646610080_valenzuelaluis";
char password[] = "Utd_2020";       
char BASE_SQL[] = "INSERT INTO u646610080_valenzuelaluis.hello_sensor (message, sensor, value) VALUES ('%s', '%d', '%s');";
char consulta[128];
EthernetClient client;
MySQL_Connection conn((Client *)&client);  //Asocia el cliente al conector MySQL 

void setup() {  
  Serial.begin(115200);
  while (!Serial);
  Ethernet.begin(mac_addr); 
  Serial.print("  IP asignada por DHCP: ");
  Serial.println(Ethernet.localIP());
  Serial.println("Conectando...");
  delay(1000);
  if (conn.connect(server_addr, 3306, user, password)) {  
    delay(1000);
  }
  else
    Serial.println("Connection failed.");
}

void loop() {
  delay(1000);

  Serial.println("Guardando datos");
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);            // Inicializa el cursor para la consulta SQL
  sprintf(consulta,BASE_SQL,"milisegundos",millis());         // Completa la trama de la consulta SQL  
  Serial.println(consulta);
  
  cur_mem->execute(consulta);                                 // Ejecuta la consulta SQL y escribe el valor de los milisegundos
  sprintf(consulta,BASE_SQL,"microsegundos",micros());        // Completa la trama de la consulta SQL  
  Serial.println(consulta);  
  
  cur_mem->execute(consulta);                                 // Ejecuta la consulta SQL y escribe el valor de los microsegundos
  delete cur_mem;                                             // Al no haber resultados, elimina el cursor y libera memoria
}
