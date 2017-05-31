
/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#include "pitches.h"

int greenPin = 6;


int redPin = 9;


int bluePin = 5;


int counter = 0;


// notes in the melody:
int melody[] = {
  NOTE_DS5,NOTE_DS5,NOTE_E5,NOTE_B4,NOTE_GS4,NOTE_DS5,NOTE_DS5,NOTE_E5,NOTE_B4,NOTE_GS4,NOTE_DS5,NOTE_DS5,NOTE_E5,NOTE_B4,NOTE_GS4,NOTE_DS5,NOTE_DS5,NOTE_E5,NOTE_DS5,NOTE_B4,NOTE_GS4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  2,8,4,4,16,2,8,4,4,16,2,8,4,4,16,2,8,8,8,8,8
};

void setup() {

  pinMode(greenPin,OUTPUT);


  pinMode(redPin,OUTPUT);
  
  
  pinMode(bluePin,OUTPUT);

  
  // iterate over the notes of the melody:

}

void loop() {
  // no need to repeat the melody.
    for (int thisNote = 0; thisNote < 21; thisNote++) {
    counter=thisNote%3;

if(counter == 0){//紅綠同時點亮，產生黃色


analogWrite(greenPin,255);


analogWrite(redPin,255);


analogWrite(bluePin,0);


}


else if(counter == 1){//藍紅同時點亮，產生紫色


analogWrite(greenPin,0);


analogWrite(redPin,255);


analogWrite(bluePin,255);


}


else if(counter == 2){//藍綠同時點亮，產生青色


analogWrite(greenPin,255);


analogWrite(redPin,0);


analogWrite(bluePin,255);


counter = 0;


}

    
    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1500/8, etc.
    int noteDuration = 1170 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:

  
    
    noTone(8);
  }




}
