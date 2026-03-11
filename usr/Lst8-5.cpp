/* TITLE */
/*
Purpose: Display an int array using array indexes
Dr. Purdum, Mar. 11, 2015
*/
#include <Arduino.h>
// Define global definitions here:

//put function declarations here:

void setup() {
  Serial.begin(9600);

  int greet[6]; // Notice this is an int now
  int *ptr;     // ...as is this
  int i;
  greet[0] = 0; // Numbers now...
  greet[1] = 1;
  greet[2] = 2;
  greet[3] = 3;
  greet[4] = 4;
  greet[5] = 5;
  Serial.print("Using 'Serial.print(greet[i]);' ");
  for (i = 0; i < 5; i++)
  {
      Serial.print(greet[i]); // Flavor #1
  }
  Serial.println();
  Serial.print("Using 'Serial.print(*(greet + i));' ");
  for (i = 0; i < 5; i++)
  {
      Serial.print(*(greet + i)); // Flavor #2
  }
  Serial.println();
  Serial.print("Using 'Serial.print(*ptr++);' ");
  ptr = greet;
  for (i = 0; i < 5; i++)
  {
      Serial.print(*ptr++); // Flavor #3
  }
}

void loop() {
    
}

//put function definitions here: