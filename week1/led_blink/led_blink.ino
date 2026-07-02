/*
----------------------------------------------------
Author      : Rubadharshini S
Date        : 02-07-2026
Program     : LED Blink
Description : Blinks the built-in LED every 1 second.
----------------------------------------------------
*/

int count = 0;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(500);

  digitalWrite(13, LOW);
  delay(500);

  count++;

  Serial.print("Blink count: ");
  Serial.println(count);
}
