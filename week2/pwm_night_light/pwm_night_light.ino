/*
  PWM Fading Night Light
  Author: Rubadharshini
*/

const int ledPin = 9;
const int buttonPin = 2;

int mode = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Mode 1: Slow Breathing");
}

void loop() {

  if (digitalRead(buttonPin) == LOW) {
    mode++;
    if (mode > 2) mode = 0;

    if (mode == 0)
      Serial.println("Mode 1: Slow Breathing");
    else if (mode == 1)
      Serial.println("Mode 2: Fast Pulse");
    else
      Serial.println("Mode 3: SOS");

    delay(300);
  }

  if (mode == 0) {
    breathing(15);
  }
  else if (mode == 1) {
    breathing(2);
  }
  else {
    sos();
  }
}

void breathing(int speedDelay) {
  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(speedDelay);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(speedDelay);
  }
}

void sos() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }

  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(600);
    digitalWrite(ledPin, LOW);
    delay(200);
  }

  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }

  delay(1000);
}
