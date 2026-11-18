#include "Arduino_SensorKit.h"
#include <AsyncTimer.h>      //timer
#define LED 6                //Pin 6 Licht
#define pump 7               //pin 7 Pumpe
#define feuchtsr A1           //pin A1 Feuchtigkeitssensor
AsyncTimer timer;            //timer
int moisture = 0; 


void setup() {

	Serial.begin(9600);
    Serial.println("Serial Setup Complete");
    pinMode(6, OUTPUT);    // pin 6 auf Ausgang stellen
    pinMode(7, OUTPUT);    // pin 7 auf Ausgang stellen
    Serial.println("PIN Setup Complete");

    timer.setInterval(pumpe, 20000); //alle 24h number to use 86388000
    timer.setInterval(light, 10000); //alle 12h number to use 43200000
    timer.setInterval(screen, 20000);
    timer.setInterval(feuchtigkeitsensor, 20000);
    Serial.println ("Timer Setup complete"); 

    Oled.begin();	
    Oled.setFlipMode(true); // Sets the rotation of the screen
    Serial.println("Screen Setup complete"); 
    
    delay (1000);
    digitalWrite(6, HIGH);
    delay (5000);
	Serial.println("Light Setup complete"); 
}


void loop() {
  timer.handle();
}


void pumpe() {
    digitalWrite(7, HIGH);  //Pumpe an 
    Serial.println ("Pumpe an");
    delay(800);            //8ms Delay Pumpen
    digitalWrite(7, LOW);   //Pumpe aus 
    Serial.println ("Pumpe aus");



}

void light() {
  if (digitalRead(6) == HIGH) {
    digitalWrite(6, LOW);
    Serial.println("Licht aus");
  }
  else {
    digitalWrite(6, HIGH);
    Serial.println("Licht an");
  }
}

void feuchtigkeitsensor() {
    moisture = analogRead(feuchtsr);
    Serial.println("Feuchtigkeit:");
    Serial.println(moisture);

}

void screen() {
    Oled.setFont(u8x8_font_chroma48medium8_r);
    Oled.setCursor(0, 33);    // Set the Coordinates 
    Oled.print("Feuchtigkeit:");
    Oled.print(moisture);
    Oled.print(" ");
    Oled.refreshDisplay();
}
