// Q22 - Ultrasonic Parking Sensor
// Author: Rubadharshini
// Description: Parking distance alert using HC-SR04

#define TRIG_PIN 9
#define ECHO_PIN 10

#define YELLOW_LED 3
#define RED_LED 4
#define BUZZER 5

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  pinMode(BUZZER, OUTPUT);
}

void loop() {

  long duration;
  float distance;

  // Generate ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  // Read echo pulse
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm - ");

  // SAFE
  if (distance > 50) {

    Serial.println("SAFE");

    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
    noTone(BUZZER);

    delay(500);
  }

  // CAUTION
  else if (distance > 20) {

    Serial.println("CAUTION");

    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    tone(BUZZER, 1000);
    delay(100);
    noTone(BUZZER);
    delay(400);
  }

  // WARNING
  else if (distance > 10) {

    Serial.println("WARNING");

    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);

    tone(BUZZER, 1000);
    delay(100);
    noTone(BUZZER);
    delay(100);
  }

  // STOP
  else {

    Serial.println("STOP");

    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, HIGH);

    tone(BUZZER, 1000);
    delay(100);

    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
    delay(100);
  }
}
