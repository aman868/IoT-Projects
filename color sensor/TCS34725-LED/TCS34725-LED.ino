//Follow us on other social media

//https://www.youtube.com/c/ZinTechIdeas
//https://www.facebook.com/zin.techideas.3
//https://www.instagram.com/zintechideas/
//https://twitter.com/Zintechideas
//https://zintechideas.ir/
#include <Wire.h>
#include "Adafruit_TCS34725.h"

#define redpin 3
#define greenpin 5
#define bluepin 6

#define commonAnode true


byte gammatable[256];


Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  Serial.begin(9600);
  
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
  
  tcs.setInterrupt(false); 

  delay(60);

  tcs.getRGB(&red, &green, &blue);
  
  tcs.setInterrupt(true);

  Serial.print("R:\t"); Serial.print(int(red)); 
  Serial.print("\tG:\t"); Serial.print(int(green)); 
  Serial.print("\tB:\t"); Serial.print(int(blue));
  
  analogWrite(redpin, gammatable[(int)red]);
  analogWrite(greenpin, gammatable[(int)green]);
  analogWrite(bluepin, gammatable[(int)blue]);

}
