#include <Wire.h>
#include <rgb_lcd.h>
#include "pitches.h"

/* Inputs and Outputs */
#define BUTTON1 2
#define BUTTON2 3
#define TOUCH   4 
#define LIGHT   A0
#define POT1    A1
#define POT2    A2
#define SPEAKER 6

/* Durations */
#define EIGHTH    125
#define QUARTER   250
#define HALF      500
#define FULL      1000
#define SIXTEENTH 63
#define WAIT_RATIO 1.3

/* LCD */
rgb_lcd lcd;
int red = 128;
int green = 128;
int blue = 128; 

/* Variables */
int curr_note = NOTE_C4;
int curr_dur = QUARTER;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(TOUCH, INPUT);
  
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setRGB(red, green, blue);

  lcd.print("hello, world!");

  playDiddy2(SPEAKER);
  delay(2000);
  playDiddy3(SPEAKER);
}

void printStatus(void) {
  Serial.print("BUTTON1: "); Serial.print(digitalRead(BUTTON1));
  Serial.print(" BUTTON2: "); Serial.print(digitalRead(BUTTON2));
  Serial.print(" TOUCH: "); Serial.print(digitalRead(TOUCH));
  Serial.print(" POT1: "); Serial.print(analogRead(POT1));
  Serial.print(" POT2: "); Serial.print(analogRead(POT2));
  Serial.print(" LIGHT: "); Serial.println(analogRead(LIGHT));
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //printStatus();
  //tone(SPEAKER, curr_note, curr_dur); delay(curr_dur * WAIT_RATIO);
}
