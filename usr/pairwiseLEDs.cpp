#include <Arduino.h>
// Define global definitions here:
#define ARRAYLENGTH(x) (sizeof(x) / sizeof(x[0]))

int ledPins[] = {4, 5, 6, 7, 8, 9, 10, 11};
// put function declarations here:

void setup()
{
    for (int i = 0; i < ARRAYLENGTH(ledPins); i++)
    {
        pinMode(ledPins[i], OUTPUT);
    }
}

void loop()
{
    for (int i = 0; i < ARRAYLENGTH(ledPins); i++)
    {
        digitalWrite(ledPins[i], HIGH);
        byte ledPair = ARRAYLENGTH(ledPins) - i -1; // opposite pair led to light
        digitalWrite(ledPins[ledPair], HIGH);
        delay(500);
        digitalWrite(ledPins[i], LOW);
        digitalWrite(ledPins[ledPair], LOW);
    }
}