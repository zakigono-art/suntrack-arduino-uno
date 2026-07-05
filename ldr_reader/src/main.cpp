#include <Arduino.h>
#include <Servo.h>

// Pins
const int LDR_PINS[] = {A0, A1, A2, A3};
const int SERVO_H_PIN = 8;
const int SERVO_V_PIN = 9;

// Constants
const int STOP = 90;
const int DEADZONE = 10;
const int SPEED_CW = 97;
const int SPEED_CCW = 83;

// 5° movement ≈ 85ms pulse
const unsigned long PULSE_MS = 85;
const unsigned long WAIT_MS = 3000;

Servo servoH, servoV;

void setup() {
  Serial.begin(9600);
  servoH.attach(SERVO_H_PIN);
  servoV.attach(SERVO_V_PIN);
  servoH.write(STOP);
  servoV.write(STOP);
}

void loop() {
  int val[4];
  for (int i = 0; i < 4; i++) val[i] = analogRead(LDR_PINS[i]);

  // Calculate differences
  int diffH = ((val[1] + val[2]) / 2) - ((val[0] + val[3]) / 2);
  int diffV = ((val[0] + val[1]) / 2) - ((val[2] + val[3]) / 2);

  // Check if all sensors are similar (diffH and diffV within similarity threshold of e.g. 60 units)
  const int SIMILARITY_THRESHOLD = 60;
  if (abs(diffH) <= SIMILARITY_THRESHOLD && abs(diffV) <= SIMILARITY_THRESHOLD) {
    servoH.write(STOP);
    servoV.write(STOP);
    delay(100);
    return; // skip movement logic
  }

  // Move Horizontal
  if (abs(diffH) > DEADZONE) {
    servoH.write(diffH > 0 ? SPEED_CW : SPEED_CCW);
    delay(PULSE_MS);
    servoH.write(STOP);
    delay(WAIT_MS);
  }

  // Move Vertical
  if (abs(diffV) > DEADZONE) {
    servoV.write(diffV > 0 ? SPEED_CCW : SPEED_CW);
    delay(PULSE_MS);
    servoV.write(STOP);
    delay(WAIT_MS);
  }

  delay(100);
}