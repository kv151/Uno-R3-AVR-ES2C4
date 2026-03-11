/* TITLE */
#include <Arduino.h>
#include<string.h>
//Define global definitions here:

//put function declarations here:

void setup() {
    Serial.begin(9600);

    char buffer[50];
    char *ptr;
    int i;
    int length;

    strcpy(buffer, "When in the course of human events");

    ptr = buffer;
    length = strlen(buffer);

    Serial.print("The lvalue for ptr is: ");
    Serial.print((unsigned int)&ptr);
    Serial.print(" and the rvalue is ");
    Serial.println((unsigned int)ptr);
    while (*ptr) //increments until the null termination \0 in the array. 
    {
        Serial.print(*ptr++); 
    }
    for (i=0; i < length; i++) {
        Serial.print(*(ptr + i)); // resolves to 536903316 + 1 (past the end of the array buffer[]) now we will clear it
    }
    
    ptr = buffer;
    Serial.println("") ; // prints a new line
    for (i = 0; i < length; i++)
    {
        Serial.print(*(ptr + i)); // resolves to 536903316 + 1 (past the end of the array buffer[]) now we will clear it
    }
}

void loop() {

}

//put function definitions here: