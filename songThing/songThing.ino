// ---------------------------------------------------------------------------
// Connect speaker to these pins:
//   Pins  9 & 10 
// Be sure to include an inline 100 ohm resistor on one pin .
// ---------------------------------------------------------------------------

#include <toneAC.h>
#include "pitches.h"

// Melody liberated from the toneMelody Arduino example sketch by Tom Igoe.
int melody[] = { NOTE_E3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_C2, NOTE_C2, NOTE_D3, NOTE_E3, NOTE_E3, NOTE_D3, NOTE_D3, NOTE_E3, NOTE_E3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_C2, NOTE_C2, NOTE_D3, NOTE_E3,
                 NOTE_D3, NOTE_C2, NOTE_C2, NOTE_D3, NOTE_D3, NOTE_E3, NOTE_C2, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_E3, NOTE_C2, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_C2, NOTE_D3, NOTE_E3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_C2, NOTE_C2, NOTE_D3, NOTE_E3, NOTE_D3, NOTE_C2, NOTE_C2};
int noteDurations[] = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 8 ,2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 8, 2, 4, 4, 4, 4, 4, 8, 8, 4, 4, 4, 8, 8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 8, 2};

int senspin = A0;
int sensorReading;

int inPin = 2;
int reading;
int previous = LOW; 
int state = HIGH;


int sensVol;

void setup() {
  
    pinMode(inPin, INPUT);
    digitalWrite(inPin, HIGH);
    Serial.begin(9600);
  
} 

void loop() {
  
      sensorReading = analogRead(senspin);    
     sensVol = sensorReading/90;
  
  Serial.println(sensVol);

    
  if(sensVol > 10){
    
    sensVol = 10;
    
  } 
 
  toneAC(); // Turn off toneAC, can also use noToneAC().

  //delay(1000); // Wait a second.
  
  

  for (int thisNote = 0; thisNote < 61; thisNote++) {
     sensorReading = analogRead(senspin);    
     sensVol = sensorReading/90;
  
  Serial.println(sensVol);
    int noteDuration = 1000/noteDurations[thisNote];
    toneAC(melody[thisNote], sensVol, noteDuration, true); // Play thisNote at full volume for noteDuration in the background.
    delay(noteDuration * 4 / 3); // Wait while the tone plays in the background, plus another 33% delay between notes.
  }

}





