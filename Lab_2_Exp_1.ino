
/*
Lab 2 - Experiment 1
 Parth Soni
 DIGF 2B03 Physical Computing S01
 OCAD University
 Created on [Jan 17th 2015]
 
 Based on:
 Play a Melody using the tone() function, Arduino, http://arduino.cc/en/Tutorial/Tone
 Fade, Arduino built-in Sketches
 */

// Defining values
int switch1 = 7; 
int switch2 = 8;
int switch3 = 4;
int speakerPin = 6;
int ledPin = 9;
int brightness = 0;    
int fadeAmount = 5;    

void setup () {

  //pin Modes Inputs
  pinMode (switch1, INPUT_PULLUP);
  pinMode (switch2, INPUT_PULLUP);
  pinMode (switch3, INPUT_PULLUP);
  // pin modes Outputs
  pinMode (speakerPin, OUTPUT);
  pinMode (ledPin, OUTPUT);

}

void loop () {

  // switch reads
  int switch1Value = digitalRead(switch1);
  int switch2Value = digitalRead(switch2);
  int switch3Value = digitalRead(switch3);

  // Playing different sequences on different inputs
  if (switch1Value == LOW) {
    fadeSequence ();
  }

  if (switch2Value == LOW) {
    noiseSequence ();
  }

  if (switch3Value == LOW) {
    steadySequence ();
  }

  else {
    digitalWrite(ledPin, LOW);
    digitalWrite (speakerPin, LOW);
    noTone(speakerPin);
  }
}

void steadySequence () {
  analogWrite (ledPin, 150);
  tone (speakerPin, 500, 50);

}

void noiseSequence () {
  analogWrite (ledPin, random (2,100));
  tone(speakerPin, random (200,300),50);
}

void fadeSequence () {

  // Brightness of LEDs:
  analogWrite(ledPin, brightness);    
  tone(speakerPin, brightness*2,50);

  // Brightness Amount
  brightness = brightness + fadeAmount;

  // Fade Reverse 
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }  

  delay(30);     
}
