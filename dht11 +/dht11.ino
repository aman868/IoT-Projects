#include <Wire.h>               // Include the Wire library for I2C communication
#include <LiquidCrystal_I2C.h>  // Include the LiquidCrystal_I2C library for I2C display
#include <DHT.h>                // Include the DHT library for DHT11 sensor

#define DHTPIN 2                // DHT11 sensor connected to digital pin 2
#define DHTTYPE DHT11           // DHT11 sensor type

DHT dht(DHTPIN, DHTTYPE);        // Initialize the DHT11 sensor object
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Initialize the I2C display object with the I2C address and display dimensions

void setup() {
  lcd.begin(16, 2);             // Initialize the display
  lcd.print("Temperature:");    // Display the initial message
  lcd.setCursor(0, 1);
  lcd.print("Humidity:");
  
  dht.begin();                  // Initialize the DHT11 sensor
}

void loop() {
  delay(2000);                  // Delay for 2 seconds
  
  float temperature = dht.readTemperature();   // Read temperature from the DHT11 sensor
  float humidity = dht.readHumidity();         // Read humidity from the DHT11 sensor
  
  lcd.setCursor(12, 0);         // Set cursor position for temperature display
  lcd.print("     ");           // Clear previous temperature value
  lcd.setCursor(12, 0);         // Set cursor position for temperature display
  lcd.print(temperature);       // Display temperature value
  
  lcd.setCursor(9, 1);          // Set cursor position for humidity display
  lcd.print("     ");           // Clear previous humidity value
  lcd.setCursor(9, 1);          // Set cursor position for humidity display
  lcd.print(humidity);          // Display humidity value
}
