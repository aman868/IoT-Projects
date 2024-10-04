#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); // RX, TX

// Define relay pins
int relayLight = 9;
int relayFan = 10;

void setup() {
  // Set up relay pins as OUTPUT
  pinMode(relayLight, OUTPUT);
  pinMode(relayFan, OUTPUT);
  
  // Start communication with the Bluetooth module
  BTSerial.begin(9600);
  
  // Start serial communication for debugging
  Serial.begin(9600);
  Serial.println("Bluetooth relay control ready.");
}

void loop() {
  // Check if there's incoming data from the Bluetooth module
  if (BTSerial.available()) {
    char command = BTSerial.read();
    
    // Debugging: Print the received command
    Serial.println(command);
    
    // Control the relay based on the received command
    switch (command) {
      case 'light on':   // Turn ON light
        digitalWrite(relayLight, HIGH);
        BTSerial.println("Light ON");
        break;
        
      case 'light off':   // Turn OFF light
        digitalWrite(relayLight, LOW);
        BTSerial.println("Light OFF");
        break;
        
      case '3':   // Turn ON fan
        digitalWrite(relayFan, HIGH);
        BTSerial.println("Fan ON");
        break;
        
      case '4':   // Turn OFF fan
        digitalWrite(relayFan, LOW);
        BTSerial.println("Fan OFF");
        break;
        
      default:
        BTSerial.println("Invalid Command");
        break;
    }
  }
}