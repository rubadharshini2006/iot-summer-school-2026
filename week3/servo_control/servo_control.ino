#include <Servo.h>

Servo myServo;

#define POT A0
#define BTN 2

bool sweepMode = false;

void setup() {
  myServo.attach(9);   // Servo signal pin
  pinMode(BTN, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // Read potentiometer and map to angle
  int potValue = analogRead(POT);
  int angle = map(potValue, 0, 1023, 0, 180);

  // Button press → sweep mode
  if (digitalRead(BTN) == LOW) {
    sweepMode = true;
    delay(300); // debounce
  }

  if (sweepMode) {
    // Sweep 0 → 180
    for (int i = 0; i <= 180; i++) {
      myServo.write(i);
      Serial.print("Sweep Angle: ");
      Serial.println(i);
      delay(10);
    }

    // Sweep 180 → 0
    for (int i = 180; i >= 0; i--) {
      myServo.write(i);
      Serial.print("Sweep Angle: ");
      Serial.println(i);
      delay(10);
    }

    sweepMode = false;
  }
  else {
    // Normal control using potentiometer
    myServo.write(angle);

    Serial.print("Angle: ");
    Serial.println(angle);
  }

  delay(50);
}
