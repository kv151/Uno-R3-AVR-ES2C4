/* TITLE */
/* pass by value vs pass by reference*/
#include <Arduino.h>
//Define global definitions here:

//put function declarations here:
void SquareIt(int *temp);

void setup() {
    Serial.begin(9600);
    int number = 10;

    Serial.print("lvalue for number is ");
    Serial.print((int)&number);
    Serial.print(" rvalue for number is ");
    Serial.println(number);
    
    SquareIt(&number);
    Serial.print("After call: rvalue for number is ");
    Serial.println(number);
}

void loop() {
    
}

//put function definitions here:
void SquareIt(int *temp) {
    Serial.print("In SquareIt(), lvalue for temp is ");
    Serial.print((int)&temp);
    Serial.print(" rvalue for temp is ");
    Serial.println(*temp);
    *temp = *temp * *temp;
    Serial.print("The new rvalue for temp is ");
    Serial.println(*temp);
}