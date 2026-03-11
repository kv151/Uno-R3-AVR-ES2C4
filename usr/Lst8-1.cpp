/* TITLE */
#include <Arduino.h>
#include <stdio.h>
//Define global definitions here:
int counter = 0;
//put function declarations here:

void setup() {
    int number = 5;
    int *ptrNumber;
    int k;

    Serial.begin(9600);
    Serial.print("The lvalue for ptrNumber is: ");
    Serial.print((long) &ptrNumber, DEC);
    Serial.print(" and the rvalue is ");
    Serial.println((long)ptrNumber, DEC);

    //=== Put new statements here!
    ptrNumber = &number;
    *ptrNumber = 10;
    k = *ptrNumber;

    Serial.print("The lvalue for number is: ");
    Serial.print((long)&number, DEC);
    Serial.print(" and has an rvalue of ");
    Serial.println((int)number, DEC);

    Serial.print("The lvalue for k: ");
    Serial.print((long)&k, DEC);
    Serial.print(" and has an rvalue of ");
    Serial.println(k, DEC);
}

void loop() {
    
}

//put function definitions here: