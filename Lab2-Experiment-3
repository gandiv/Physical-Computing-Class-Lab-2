
/*
Lab 2 - Experiment 3
 Parth Soni
 DIGF 2B03 Physical Computing S01
 OCAD University
 Created on [Jan 20th 2015]
 
 Based on:
 Capacitive Sensors, Arduino,http://playground.arduino.cc/Main/CapacitiveSensor?from=Main.CapSense
 Fading RGB LED by cyragia : http://www.instructables.com/id/Fading-RGB-LED-Arduino/step3/Code/
 */
 
#include <CapacitiveSensor.h>


CapacitiveSensor cs_2_A1 = CapacitiveSensor(2,A1); // Pins A1 to 2
CapacitiveSensor cs_4_A0 = CapacitiveSensor(4,A0); // Pins A0 to 4

int green = 9;
int blue = 10;
int red = 11;
int delayTime = 1;
int redVal;
int blueVal;
int greenVal;
int Apin = A0; 
int Bpin = A1;
int A,B;

void setup()
{ 
Serial.begin(9600);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);

}
void loop()
{
// Reading Foil Data if any connection with the pencil has been made, and Where?
A = cs_4_A0.capacitiveSensor(30);
B = cs_2_A1.capacitiveSensor(30);


// If the strokes are Controlled
if (A>15){
RGBLedFunction ();
}
//If the Strokes are Expressive
else if (B>15){
randomRGBLedFunction ();
}
// if no strokes, Turn it off
else {
    digitalWrite (red, LOW);
  digitalWrite (green, LOW);
  digitalWrite (blue, LOW);
}
delay (10);
}
void randomRGBLedFunction () {
  analogWrite (red, random (2,100));
  analogWrite (green, random (2,100));
  analogWrite (blue, random (2,100));

}
void RGBLedFunction () {
  // All of this Code below was taken from that Instructable Tutorial
  // It didn't come with comments, so i am making my own comments to show my understanding
  int redVal = 255; // Red Value at maximum
  int blueVal = 0; // Blue Value at 0
  int greenVal = 0; // Green Value at 0
  
  // Red Goes Down and Green Values go up, so it mixes in
  for( int i = 0 ; i < 255 ; i += 1 ){
    greenVal += 1;
    redVal -= 1;
    analogWrite( green, 255 - greenVal );
    analogWrite( red, 255 - redVal );

    delay( delayTime );
  }
 
 // Green Values Go down and Blue Goes up
  redVal = 0;
  blueVal = 0;
  greenVal = 255;
  for( int i = 0 ; i < 255 ; i += 1 ){
    blueVal += 1;
    greenVal -= 1;
    analogWrite( blue, 255 - blueVal );
    analogWrite( green, 255 - greenVal );

    delay( delayTime );
  }
 
 //Blue Values go Down and Red Values go up
  redVal = 0;
  blueVal = 255;
  greenVal = 0;
  for( int i = 0 ; i < 255 ; i += 1 ){
    redVal += 1;
    blueVal -= 1;
    analogWrite( red, 255 - redVal );
    analogWrite( blue, 255 - blueVal );

    delay( delayTime );
  }
}
