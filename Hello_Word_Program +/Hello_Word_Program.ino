#include <Wire.h>  // Include the I2C library
#include <LiquidCrystal_I2C.h>  // Include the LCD library

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Set the LCD address to 0x27 for a 16x2 display

void setup() {
  lcd.begin(16, 2);// Initialize the LCD
  lcd.backlight();  // Turn on the backlight
  lcd.setCursor(0, 0);  // Set the cursor to the top-left corner
  lcd.print("WELCOME TO IOT");  // Display "Hello, World!" on the LCD
}

void loop() {
  // The loop function is not used in this example
}
