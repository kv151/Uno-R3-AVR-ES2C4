/* TITLE */
#include <Arduino.h>
#include <avr/interrupt.h> //cotains symbolic constnats for interrupts

#define LED_PIN 12
#define BUTTON_PIN 2
//Define global definitions here:
volatile int LED_state = LOW; //default led state

//put function declarations here:

void setup() {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN,LOW); //turn of the LED on pin 12
    pinMode(BUTTON_PIN, INPUT);    

    EICRA |= (1 << ISC01); //set pin ISCO1
    EICRA &= ~(1 << ISC00); //reset pin ISC00 on falling edge
    /* Bit shift or mask set:
    It’s a concise way to create a bitmask—a value with a single bit set to 1 at the position you want to modify in the register.
    In this case, it creates a value that will set the ISC01 bit in EICRA to 1, while leaving all other bits unchanged.

    The |= operator performs a bitwise OR between the current value of EICRA and the value on the right ((1 << ISC01)), then stores the result back in EICRA. This means only the bit at position ISC01 is set to 1; all other bits remain as they were.
    */

    sei(); //TURN ON INTERRUPTS
}

void loop() {
    /* make some dummy program to run that can be interuptted by the button*/
    unsigned long i;
    unsigned long sum = 0;
    for (i = 0; i < 4000000; i ++) {
        sum++;
    }
}

//put function definitions here:

ISR(INT0_vect) {
    LED_state = ! LED_state; 
    digitalWrite(LED_PIN,LED_state); //flip the led on an interrupt
}