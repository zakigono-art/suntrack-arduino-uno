// LED Blink Test - 5 second interval
// Upload to verify board connection and basic functionality

const int LED_PIN = LED_BUILTIN;
const unsigned long INTERVAL = 5000;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Blink test started - 5s interval");
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("ON");
  delay(INTERVAL);
  digitalWrite(LED_PIN, LOW);
  Serial.println("OFF");
  delay(INTERVAL);
}
