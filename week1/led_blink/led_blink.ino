/*
----------------------------------------------------
Author      : Rubadharshini S
Date        : 02-07-2026
Program     : LED Blink
Description : Blinks the built-in LED every 1 second.
----------------------------------------------------
*/

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(500);

  digitalWrite(13, LOW);
  delay(500);
}
