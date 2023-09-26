// Pin assignments
const int ldrPin = A0;    // LDR module connected to analog pin A0
const int ledPin = 13;    // LED connected to digital pin 13

// Threshold values
const int lightThreshold = 500;   // Adjust this value to set the light sensitivity

void setup() {
  pinMode(ledPin, OUTPUT);    // Set LED pin as output
  digitalWrite(ledPin, LOW);  // Turn off LED initially
  Serial.begin(9600);         // Initialize serial communication for debugging
}

void loop() {
  int lightLevel = analogRead(ldrPin);  // Read the light level from the LDR module
  
  Serial.print("Light Level: ");
  Serial.println(lightLevel);
  
  if (lightLevel > lightThreshold) {
    digitalWrite(ledPin, HIGH);   // Turn on LED if light level is below threshold
  } else {
    digitalWrite(ledPin, LOW);    // Turn off LED if light level is above threshold
  }
  
  delay(100);  // Delay for smoother readings (optional)
}
