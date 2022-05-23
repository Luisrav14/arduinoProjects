
int sensorPin = A0;
int valorSensor = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  delay(1000);
  Serial.println(valorSensor,DEC);

}
