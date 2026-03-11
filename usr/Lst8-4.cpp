/* TITLE */
/*
Purpose: Display a character array using array indexes
Dr. Purdum, Nov 22, 2014
*/
#include <Arduino.h>
// Define global definitions here:

//put function declarations here:

void setup() {
   char greet[6];
   int i;
   
   Serial.begin(9600);

   greet[0] = 'H'; // Initialize the array with some characters
   greet[1] = 'e'; // the slow way...
   greet[2] = 'l';
   greet[3] = 'l';
   greet[4] = 'o';
   greet[5] = '\0'; // null termination character

   for (i = 0; i <5; i++) {
    Serial.print(greet[i]);
   }
    for (int j = 0; j < 5 ; j++) {
        Serial.print(*(greet+j));
   }
    for (int k = 0; k < 5;k++) {
        Serial.print(*(greet + k*sizeof(char)));
   }
}

void loop() {
    
}

//put function definitions here: