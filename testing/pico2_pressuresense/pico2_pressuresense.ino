const int ADC_PIN = 26;
const float VREF = 3.3f;
const float ADC_MAX = 4095.0f;
const float DIVIDER_SCALE = 32.0f / 22.0f;
const float VOUT_AT_ZERO = 2.5f;
const float SENSITIVITY = 1.0f;

unsigned long startTime;


void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  delay(500);
  Serial.println("time_ms,raw_adc,voltage_v,pressure_kpa");
  startTime = millis();

}

void loop() {
  int raw = analogRead(ADC_PIN);
  float vMeasured = (raw / ADC_MAX) * VREF;
  float vActual = vMeasured * DIVIDER_SCALE;
  float pressure = (vActual - VOUT_AT_ZERO);

  unsigned long t = millis() - startTime;

  Serial.print(t);
  Serial.print(",");
  Serial.print(raw);
  Serial.print(",");
  Serial.print(vActual, 4);
  Serial.print(",");
  Serial.println(pressure, 4);

  delay(20);

}
