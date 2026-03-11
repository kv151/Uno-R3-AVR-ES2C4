/* TITLE */
#include <Arduino.h>
//Define global definitions here:
#define ARRAYLENGTH(x) (sizeof(x)/sizeof(x[0]))

int ledPins[] = {4,5,6,7,8,9,10,11};
//put function declarations here:
int ConvertToBinary(int numberinDecimal);
void DisplayBinaryDigit(byte numberinBinary);


//setup
void setup() {
    for (int i = 0; i < ARRAYLENGTH(ledPins); i++) {
        pinMode(ledPins[i], OUTPUT);
    }

    Serial.begin(9600);
}

//loop
void loop() {
    // for (int i = 0; i < ARRAYLENGTH(ledPins); i++) {
    //     digitalWrite(ledPins[i], HIGH);
    //     delay(500);
    //     digitalWrite(ledPins[i], LOW);
    // }

    char buff[4];
    int charsRead, numberinDecimal;

    if (Serial.available()>0) {
        charsRead = Serial.readBytesUntil('\n', buff, 3);
        buff[charsRead] = '\0';
        numberinDecimal = atoi(buff);

        if (numberinDecimal >= 0 && numberinDecimal <= 255) {
            ConvertToBinary(numberinDecimal);
            DisplayBinaryDigit(numberinDecimal);
        }
    }
    
}

//put function definitions here:
/*****
Purpose: Light up LEDS in a line to represent the binary number.

Parameter list:
    byte binaryNumber - the byte containing a number from an 8 bit unsigned integer

Return value:
  void - the leds light up
*****/
void DisplayBinaryDigit(byte binaryNumber) {
    for (int i = 0; i < ARRAYLENGTH(ledPins); i++) {
        if (bitRead(binaryNumber,i)==1) {
            digitalWrite(ledPins[i], HIGH);
        } else {
            digitalWrite(ledPins[i],LOW);
        }
    }
}

/*****
Purpose: To convert a decimal integer into a binary number

Parameter list:
  type name - description
  type name - description

Return value:
  type - description
*****/
int ConvertToBinary(int numberinDecimal) {
    int div2check[8]; //only 8 byte integers are supported here anyway so change here if so - can update to get rid of magic numbers
    int number = numberinDecimal;
    for (int i = 0; i < ARRAYLENGTH(div2check); i++) {
        div2check[i] = number%2;
        number /= 2;
    }
    Serial.print("Number in binary is: ");
    Serial.println("");
    for (int i = ARRAYLENGTH(div2check) - 1; i > 0; i--) {
        Serial.print(div2check[i]);
    }
    Serial.println("");
}