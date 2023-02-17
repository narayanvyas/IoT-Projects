int builtInLed = 13;
void setup() {
  pinMode(builtInLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(builtInLed, HIGH);
  delay(500);
  digitalWrite(builtInLed, LOW);
  delay(500);
}
