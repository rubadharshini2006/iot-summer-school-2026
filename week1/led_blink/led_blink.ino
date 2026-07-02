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
  int sensorValue = analogRead(A0);

  int speed = map(sensorValue, 0, 1023, 100, 1000);

  digitalWrite(13, HIGH);
  delay(speed);

  digitalWrite(13, LOW);
  delay(speed);

  count++;

  Serial.print("Blink count: ");
  Serial.println(count);
}
