void setup() {
  pinMode(14, OUTPUT); // DIR
  pinMode(15, OUTPUT); // STEP
  digitalWrite(14, LOW);
  Serial.begin(115200);
  while (!Serial) delay(10);
  Serial.println("READY");
}
// 2000 steps as an estimate. 100mm on T8 leadscrew 100mm/8mm/rev * 1600 steps/rev = 2000 steps
void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    if (cmd.startsWith("UP")) {
      int steps = cmd.substring(3).toInt();
      if (steps == 0) steps = 400;
      digitalWrite(14, HIGH);
      for (int i = 0; i < steps; i++) {
        digitalWrite(15, HIGH);
        delayMicroseconds(500);
        digitalWrite(15, LOW);
        delayMicroseconds(500);
      }
      Serial.println("DONE");
    }
    if (cmd.startsWith("DOWN")) {
      int steps = cmd.substring(5).toInt();
      if (steps == 0) steps = 400;
      digitalWrite(14, LOW);
      for (int i = 0; i < steps; i++) {
        digitalWrite(15, HIGH);
        delayMicroseconds(500);
        digitalWrite(15, LOW);
        delayMicroseconds(500);
      }
      Serial.println("DONE");
    }
  }
}