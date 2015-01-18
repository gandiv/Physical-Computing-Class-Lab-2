/*
Lab 2 - Experiment 2
Parth Soni
DIGF 2B03 Physical Computing S01
OCAD University
Created on [Jan 17th 2015]

Based on:
Play a Melody using the tone() function, Arduino, http://arduino.cc/en/Tutorial/Tone
Fade, Arduino built-in Sketches
*/

#include "pitches.h"

// The "Song of Storm" Melody From "Zelda: Ocarina of Time" loosely translated by me
int melody[] = 
{
  NOTE_D4,
  NOTE_F4,
  NOTE_D5,
  0, 
  NOTE_D4, 
  NOTE_F4, 
  NOTE_D5,
  0,
  NOTE_E5,
  NOTE_F5,
  NOTE_E5,
  NOTE_F5,
  NOTE_E5,
  NOTE_C5,
  NOTE_A4,
  0,
  NOTE_A4,
  NOTE_D4,
  NOTE_F4,
  NOTE_G4,
  NOTE_A4,
  0,
  NOTE_A4,
  NOTE_D4,
  NOTE_F4,
  NOTE_G4,
  NOTE_E4,

  0,
  NOTE_D4,
  NOTE_F4,
  NOTE_D5,
  0, 
  NOTE_D4, 
  NOTE_F4, 
  NOTE_D5,
  0,
  NOTE_E5,
  NOTE_F5,
  NOTE_E5,
  NOTE_F5,
  NOTE_E5,
  NOTE_C5,
  NOTE_A4,
  0,
  NOTE_A4,
  NOTE_D4,
  NOTE_F4,
  NOTE_G4,
  NOTE_A4,
  0,
  NOTE_A4,
  NOTE_D4,
  0
};

// Beat length 1/8th of note and such
int noteDurations[] = {
  8,8,8,
  2,
  8,8,8,
  2,
  4,8,8,8,8,8,8,
  2,
  4,4,8,8,8,
  2,
  4,4,8,8,8,
  2,
  8,8,8,
  2,
  8,8,8,
  2,
  4,8,8,8,8,8,8,
  2,
  4,4,8,8,8,
  2,
  4,2,
  2
};

int numOfNotes = sizeof(melody)/2; // The amount of notes
int speakerIn = 6; // Speaker Pin
long ledOn; //LED on and OFF
int ledReaction = 9; // LED 1 
int ledReaction2 = 10; //LED 2
int ledReaction3 = 11; // LED 3
int brightness = 0;    // LED brightness
int fadeAmount = 5;    // Fade Speed
int switchPin = 8; //switch pin
int switchState = 0;
long randomNumber;
void setup() {

  Serial.begin(9600);
  //Defining pin modes
  pinMode(switchPin, INPUT_PULLUP); 
  pinMode (speakerIn, OUTPUT);
  pinMode(ledReaction, OUTPUT);
  pinMode(ledReaction2, OUTPUT);
  pinMode(ledReaction3, OUTPUT);

}

void loop() {

  // Reading the Switch
  int sensorVal = digitalRead(switchPin);

  if (sensorVal == HIGH) {
    // If the Value is High & the switch state is at 0 Then do the fade sequence
    if (switchState == 0) {
      fadeSequence ();
    }
    // If the Value is High & the switch state is at 1 Then do the Dance sequence
    else if (switchState == 1) {
      lightDance();
    }

  } 
  else {
    // if the Button was pressed then Play the song
    playTheSong();
  }

}

void playTheSong () {

  // Play the Melody
  for (int thisNote = 0; thisNote < numOfNotes; thisNote++) {
    // This was presented the Arduino IDE, it's the pauses and note durations
    int noteDuration = 1000/noteDurations[thisNote];
    //Play the Tone
    tone(speakerIn, melody[thisNote],noteDuration);
    // Pauses, Arduino IDE recommanded 1.3, for me 1.35 sounded better
    int pauseBetweenNotes = noteDuration * 1.35;

    // Make the LEDs dance to the music!
    digitalWrite(ledOn,LOW);
    delay(pauseBetweenNotes);
    digitalWrite(ledOn,HIGH);

    if (ledOn > ledReaction3){
      ledOn = ledReaction;
    }
    else {
      ledOn++;
    }

    // switching between fade to light dance sequences
    switchState++;
    if (switchState > 1){
      switchState=0;
    }

  }

}
void fadeSequence () {

  // Brightness of LEDs:
  analogWrite(ledReaction, brightness);    
  analogWrite(ledReaction2, brightness);    
  analogWrite(ledReaction3, brightness);    

  // Brightness Amount
  brightness = brightness + fadeAmount;

  // Fade Reverse 
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }  

  delay(30);     
}

void  lightDance (){
  randomNumber = random(9,12);
  digitalWrite(randomNumber,HIGH);
  // pause between notes
  delay(random (10,200)); 
  digitalWrite(randomNumber,LOW);

}
