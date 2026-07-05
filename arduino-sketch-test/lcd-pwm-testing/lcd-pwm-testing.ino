// LCD + PWM Testing
// Tests LCD display and PWM output functionality

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD I2C Address (common: 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int PWM_PIN = 9;
const int POT_PIN = A0;
int pwmValue = 0;

void setup() {
  Serial.begin(9600);
  
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("PWM Test");
  lcd.setCursor(0, 1);
  lcd.print("Reading pot...");
  
  // Setup PWM pin
  pinMode(PWM_PIN, OUTPUT);
  Serial.println("LCD + PWM Test started");
}

void loop() {
  // Read potentiometer for PWM value
  int raw = analogRead(POT_PIN);
  pwmValue = map(raw, 0, 1023, 0, 255);
  
  // Output PWM
  analogWrite(PWM_PIN, pwmValue);
  
  // Update LCD
  lcd.setCursor(0, 1);
  lcd.print("PWM: ");
  lcd.print(pwmValue);
  lcd.print("   ");
  
  // Serial output
  Serial.print("Pot: ");
  Serial.print(raw);
  Serial.print(" PWM: ");
  Serial.println(pwmValue);
  
  delay(500);
}
