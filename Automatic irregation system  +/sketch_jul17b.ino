int motorPin = 3; // pin that turns on the motor
int blinkPin = 13; // pin that turns on the LED
int watertime = 5; // how long it will be watering (in seconds)
int waittime = 1; // how long to wait between watering (in minutes)

void setup()
{
  pinMode(motorPin, OUTPUT); // set Pin 3 to an output
  pinMode(blinkPin, OUTPUT); // set pin 13 to an output
  Serial.begin(9600);
}

void loop()
{
  int moisturePin = analogRead(A0); //read analog value of moisture sensor
  int moisture = ( 100 - ( (moisturePin / 1023.00) * 100 ) ); //convert analog value to percentage
  Serial.println(moisture);
  if (moisture < 40) { //change the moisture threshold level based on your calibration values
    digitalWrite(motorPin, HIGH); // turn on the motor
    digitalWrite(blinkPin, HIGH); // turn on the LED
    delay(watertime * 1000);      // multiply by 1000 to translate seconds to milliseconds
  }
  else {
    digitalWrite(motorPin, LOW);  // turn off the motor
    digitalWrite(blinkPin, LOW);  // turn off the LED
    delay(waittime * 10000);      // multiply by 60000 to translate minutes to milliseconds
  }

}
