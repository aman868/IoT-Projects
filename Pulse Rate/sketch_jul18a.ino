#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Change the address (0x27) to match your display

const int pulseSensorPin = A0; // Pulse rate sensor connected to analog pin A0

volatile int pulseCount = 0;
volatile boolean pulseDetected = false;

void pulseSensorInterrupt() {
  pulseCount++;
  pulseDetected = true;
}

void setup() {
  lcd.begin(16, 2);
  lcd.print("Pulse Rate:");
  lcd.setCursor(0, 1);

  attachInterrupt(digitalPinToInterrupt(pulseSensorPin), pulseSensorInterrupt, RISING);
}

void loop() {
  if (pulseDetected) {
    // Calculate pulse rate
    float pulseRate = (pulseCount * 60.0) / 7.5; // Assuming 7.5mL blood per pulse

    // Display pulse rate on LCD
    lcd.backlight();
    lcd.clear();
    lcd.print("Pulse Rate:");
    lcd.setCursor(0, 1);
    lcd.print(pulseRate, 1);

    // Reset pulse count and flag
    pulseCount = 0;
    pulseDetected = false;
  }
}
