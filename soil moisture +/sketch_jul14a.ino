#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define I2C display address and dimensions
#define I2C_ADDRESS 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// Define soil moisture sensor pin
const int soilMoisturePin = A0;

// Initialize I2C display
LiquidCrystal_I2C lcd(I2C_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize I2C display
  lcd.begin(LCD_COLUMNS, LCD_ROWS);
  lcd.backlight();

  // Display initial message
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture");
  lcd.setCursor(0, 1);
  lcd.print("Sensor Reading");

  delay(2000);
  lcd.clear();
}

void loop() {
  // Read soil moisture sensor value
  int soilMoistureValue = analogRead(soilMoisturePin);

  // Map the sensor value to a percentage (0-100%)
  int moisturePercentage = map(soilMoistureValue, 0, 1023, 0, 100);

  // Display the moisture percentage on the I2C display
  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(moisturePercentage);
  lcd.print("%");

  // Print the moisture value to the serial monitor
  Serial.print("Moisture: ");
  Serial.print(moisturePercentage);
  Serial.println("%");

  delay(1000);
}
