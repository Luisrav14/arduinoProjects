//Libraries
#include <Ethernet.h>//https://github.com/CisecoPlc/Arduino-W5100-W5200/tree/master/Ethernet
//Parameters
String request ;
unsigned long refreshCounter  = 0;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
//Objects
EthernetServer server(80);
IPAddress ip(192, 168, 1, 179);
EthernetClient client;
void setup() {
 //Init Serial USB
 Serial.begin(9600);
 Serial.println(F("Initialize System"));
 //Init W5100
 Ethernet.begin(mac, ip);
 while (!Ethernet.begin(mac)) {
   Serial.println(F("failed. Retrying in 5 seconds."));
   delay(5000);
   Serial.print(F("Starting W5100..."));
 }
 pinMode(2, OUTPUT);
 server.begin();
 Serial.println(F("W5100 initialized"));
 Serial.print(F("IP Address: "));
 Serial.println(Ethernet.localIP());
}
void loop() {
 client = server.available();
 clientRequest();
 handleRequest();
}
void clientRequest( ) { /* function clientRequest */
 ////Get client request
 if (!client) {
   return;
 }
 // Wait until the client sends some data
 while (!client.available()) {
   delay(1);
 }
 request = client.readStringUntil('\r'); // Read the first line of the request
 Serial.println(request);
 client.flush();
}
void handleRequest( ) { /* function handleRequest */
 ////Handle web client request
 if (request.indexOf('GET') >= 0) {
   {
     webpage(client);
     client.stop();
   }
 }
 if (request.indexOf("/dig2on") > 0) {
   {
     digitalWrite(2, HIGH);
   }
 }
 if (request.indexOf("/dig2off") > 0) {
   {
     digitalWrite(2, LOW);
   }
 }
}
void webpage(EthernetClient client) { /* function webpage */
 ////Send webpage to client
 //output HTML data header
 client.println(F("HTTP/1.1 200 OK"));
 client.println(F("Content-Type: text/html"));
 client.println();
 //header
 client.print(F("<!DOCTYPE HTML><html><head><title>AranaCorp</title>"));
 client.print(F("<meta http-equiv='content-type' content='text/html; charset=UTF-8'>"));
 //meta-refresh page every x seconds
 client.print(F("<meta http-equiv='refresh' content='2'>"));
 client.print(F("</head><body bgcolor='black'><br>"));
 client.print(F("<hr/><hr>"));
 client.print(F("<h1 style='color : #3AAA35;'><center> AranaCorp - Arduino Web Controller </center></h1>"));
 client.print(F("<hr/><hr>"));
 client.print("<center><p style='color:white;'>");
 client.print(F("Page refresh number : "));
 client.print(refreshCounter); //current refresh count
 client.print("</p></center><br>");
 client.print(F("<h2 style='color:green;'>Arduino Inputs</h2>"));
 client.print("<p style='color:white;'>");
 client.print("<br><br>");
 //output analog input pin
 for (int i = 0; i < 6; i++) {
   client.print("<b>Input A");
   client.print(i);
   client.print(" : </b>");
   client.print(analogRead(14 + i)); //A0=14, A1=15 ,etc.
   client.print(F("<br>"));
 }
 client.print(F("</p><br>"));
 //digital output
 client.print(F("<h2 style='color:green;'>Arduino Outputs</h2>"));
 client.print(F("<p style='color:white;'>"));
 client.print(F("<br><br>"));
 client.print(F("<b>Digital output Pin 2 : </b>"));
 client.print("<input value=" + String(digitalRead(2)) + " readonly></input>");
 client.print(F("<a href='/dig2on'><button>Turn On </button></a>"));
 client.print(F("<a href='/dig2off'><button>Turn Off </button></a><br />"));
 client.print(F("</p><br>"));
 //file end
 client.print(F("<br></body></html>"));
 refreshCounter += 1;
}
