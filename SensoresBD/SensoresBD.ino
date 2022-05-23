
#include <SPI.h>
#include <Ethernet.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>


IPAddress server_addr(92,249,45,155);
byte mac_addr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

char user[] = "u646610080_valenzuelaluis";
char password[] = "Utd_2020";   
    
char BASE_SQL[] = "INSERT INTO u646610080_valenzuelaluis.sensor_temp_hum (temperatura, humedad, nivel) VALUES ( %d , %d , %d );";
char consulta[128];

EthernetClient client;
MySQL_Connection conn((Client *)&client);

// Sensor de Temperatura y Humedad

DHT dht11(2,DHT11);

// Sensor de Nivel de Agua

const int analogInPin = A0; 
int sensorValue = 0;


void setup() {
  
  Serial.begin(115200);
  while (!Serial);
  Ethernet.begin(mac_addr); 
  Serial.print("  IP asignada por DHCP: ");
  Serial.println(Ethernet.localIP());
  Serial.println("Conectando...");
  delay(1000);
  
  if(conn.connect(server_addr, 3306, user, password)) {  
    delay(1000);
  } else {
    Serial.println("¡¡¡ Conexión Fallida !!!"); 
  }

  dht11.begin();
  
}

void loop() {

  sensorValue = analogRead(analogInPin); 
  float nivel = sensorValue*100/1024;
  float temp = dht11.readTemperature();   
  float hum = dht11.readHumidity();
  
 if (!(isnan(hum) || isnan(temp))) {    
    
    Serial.println("Guardando datos");

    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.print("°C");
    Serial.print(" | Humedad: ");
    Serial.print(hum);
    Serial.print("%");
    Serial.print(" | Nivel de Agua: ");
    Serial.print(nivel);
    Serial.print("%");
    Serial.println();

    char temp = dht11.readTemperature(); 
    char hum = dht11.readHumidity();
    char nivel = sensorValue*100/1024;
      
    MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);            // Inicializa el cursor para la consulta SQL  
    sprintf(consulta, BASE_SQL, temp, hum, nivel);              // Completa la trama de la consulta SQL  
    Serial.println(consulta);
    cur_mem->execute(consulta);                                 // Ejecuta la consulta SQL y escribe el valor de los microsegundos
    delete cur_mem;                                             // Al no haber resultados, elimina el cursor y libera memoria
    
    } else {
      Serial.println("Error de Captura");
    }

  delay(10000);
  
}
