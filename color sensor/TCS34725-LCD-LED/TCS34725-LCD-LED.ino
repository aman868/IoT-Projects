#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);


#define redpin 3
#define greenpin 5
#define bluepin 6

#define commonAnode true


byte gammatable[256];


Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  Serial.begin(9600);
  
lcd.begin();
  lcd.backlight();
  if (tcs.begin()) {
    
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); 
  }

 

  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);


  
  for (int i=0; i<256; i++) {
    float x = i;
    x /= 255;
    x = pow(x, 2.5);
    x *= 255;

    if (commonAnode) {
      gammatable[i] = 255 - x;
    } else {
      gammatable[i] = x;
    }
    
  }
}


void loop() {
  float red, green, blue;
  
  tcs.setInterrupt(false);  // turn on LED

  delay(60);  // takes 50ms to read

  tcs.getRGB(&red, &green, &blue);
  
  tcs.setInterrupt(true);  // turn off LED

  Serial.print("R:\t"); Serial.print(int(red)); 
  Serial.print("\tG:\t"); Serial.print(int(green)); 
  Serial.print("\tB:\t"); Serial.print(int(blue));
  lcd.clear();
  lcd.setCursor(2,0);
 
  lcd.setCursor(3,1);
  lcd.print("coler");
  lcd.setCursor(10,1);
  
  if(int (red)>=120){
Serial.print("\n");
   lcd.print ("red");
  }
  if(int (blue)>=120){
Serial.print("\n");
   lcd.print ("blue");
   }
   if(int (green)>=120){
Serial.print("\n");
   lcd.print ("green");
   }
   

  Serial.print("\n");


  analogWrite(redpin, gammatable[(int)red]);
  analogWrite(greenpin, gammatable[(int)green]);
  analogWrite(bluepin, gammatable[(int)blue]);

}
