#include <AsyncTimer.h>      //timer
#define LED 6                //Pin 6 Licht
#define pump 7               //pin 7 Pumpe
AsyncTimer timer;            //timer


void setup() {

	 Serial.begin(9600);
    pinMode(6, OUTPUT);    // pin 6 auf Ausgang stellen
    pinMode(7, OUTPUT);    // pin 7 auf Ausgang stellen

    timer.setInterval(pumpe, 86388000); //alle 24h
    timer.setInterval(light, 43200000); //alle 12h
    Serial.println ("Basic Setup complete"); 
    
    delay (1000);
    digitalWrite(6, HIGH);
    delay (5000);
	 Serial.println("Setup light complete");
  
 
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
