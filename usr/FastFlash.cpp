/* TITLE */
/* Program to change the blink rate of the built in LED depending on user input*/
#include <Arduino.h>
//Define global definitions here:
// #define DEBUG
#define ONBOARD 13
#define BASEBLINKRATE 1000

//put function declarations here:
int GetInput(int* passInput);
void blinkLED(int delayMode);
int blinkSetting;

void setup() {
    Serial.begin(9600);

    pinMode(ONBOARD,OUTPUT);
}

void loop() {
      int goodInput = GetInput(&blinkSetting);
      #ifdef DEBUG // debug blink setting and if GetInput worked
        Serial.print("Input flag: ");
        Serial.println(goodInput);
        Serial.print("blinkSetting: ");
        Serial.println(blinkSetting);
      #endif
      blinkLED(blinkSetting);
         
}
/*****
Purpose: Get the value of the user input from Serial monitor and update by reference the blink rate of the led

Parameter list:
  int usrInput - A number to indicate the state the user wants the LED
                    0 - LED off
                    1 - slow (1000ms delay)
                    2 - medium (5000ms delay)
                    3 - fast (333ms delay)
                    anything else - return 0 to indicate false input


Return value:
  int - 0 false input, 1 - good input
*****/
int GetInput(int *passInput) {
    int whatValue; //temporary variable to calculate what the user inteneded
    int usrInput;
    int delta = 48; // 48 is the ASCII code for 0. So we will need to subtract this from the user input character to see if the user inputted a 0,1,2 or 3 and to pass that value on to be addressed.
    *passInput = whatValue;
    while (true) {
        if (Serial.available() > 0) {
            Serial.println("Enter blink setting: 0 = off, 1 = slow, 2 = faster, 3 = fastest");
            Serial.println(""); // prints a new line
            usrInput = Serial.read();
            whatValue = usrInput - delta;
            #ifdef DEBUG //debug the io
            Serial.print("usrInput: ");
            Serial.println(usrInput);
            Serial.print("whatValue :");
            Serial.println(whatValue);
            #endif
            if (whatValue > 3 || whatValue < 0) {
                Serial.print("Error! Input is not valid. Please reset and enter a 0, 1, 2 or 3");
                return 0; //execution failed
            } else {
                *passInput = whatValue;
                return 1; //executed succesfully
            }

        } else {
            *passInput = whatValue;
        }

    }
}

/*****
Purpose: Function to blink an led at a specified with a specified delay between blinks

Parameter list:
int dealyMode -     divisor for the blink rate based on a base blink rate of 1000;
                    0 - LED off
                    1 - slow (1000ms delay)
                    2 - medium (500ms delay)
                    3 - fast (333ms delay)
                    anything else - print failure statement


Return value:
  void
*****/
void blinkLED (int delayMode){
    if (delayMode == 0) {
        digitalWrite(ONBOARD,LOW);
    }
    else if (delayMode > 0 && delayMode <= 3) {
        while (Serial.available() <= 0) { //runs the specified blink setting until a new one is entered into the console

            digitalWrite(ONBOARD,LOW);
            delay(BASEBLINKRATE/delayMode); // sets the delay mode as a fraction of the base 20000
            digitalWrite(ONBOARD,HIGH);
            delay(BASEBLINKRATE/delayMode);
        }
    } else {
        Serial.println("something has gone terribly wrong");
    }
}