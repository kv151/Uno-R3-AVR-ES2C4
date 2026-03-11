/* TITLE */
/*
Blink by Scott Fitzgerald
Modified by:
Dr. Purdum, 12/19/2014
*/
#include <Arduino.h>
// Define global definitions here:
#define LEDpin 13
//put function declarations here:
void BlinkLED(int pin, int *whichState);

void setup() {
    //init digital 13 as output
    pinMode(LEDpin,OUTPUT);
}

void loop() {
    static int state = HIGH; //initial state of LED
    BlinkLED(LEDpin, &state);
}

//put function definitions here:
/*****
Purpose: To blink the onboard LED using a pointer
Parameter List:
int pinthe pin attached to the LED
int *whichStatea pointer to the state variable back in loop()
Return value:
n/a
*****/
void BlinkLED(int pin, int *whichState) {
    digitalWrite(pin, *whichState); // turn the led to the initial HIGH or LOW
    delay(1000);
    *whichState = !(*whichState); // NOT to flip it
}