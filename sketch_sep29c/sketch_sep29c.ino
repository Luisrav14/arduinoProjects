
int led=2;

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() {
  digitalWrite(led, HIGH);
  
}
