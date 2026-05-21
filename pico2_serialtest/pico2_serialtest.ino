void setup() {
  Serial.begin(115200);
  delay(3000);
  Serial.println("HELLO");
}

void loop() {
  Serial.println("ALIVE");
  delay(1000);
}