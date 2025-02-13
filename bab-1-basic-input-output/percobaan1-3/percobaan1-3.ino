void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A2);
  Serial.println(sensorValue);
  
  digitalWrite(8, HIGH);
  delay(sensorValue);
  digitalWrite(8, LOW);
  delay(sensorValue);
}

