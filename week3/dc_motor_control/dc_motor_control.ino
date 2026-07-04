#define ENA 5
#define IN1 8
#define IN2 9

#define POT A0
#define BTN_DIR 2
#define BTN_START 3

bool direction = true;
bool motorState = true;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(BTN_DIR, INPUT_PULLUP);
  pinMode(BTN_START, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(POT);
  int speedPWM = map(potValue, 0, 1023, 0, 255);
  int speedPercent = map(potValue, 0, 1023, 0, 100);

  if (digitalRead(BTN_DIR) == LOW) {
    direction = !direction;
    delay(300);
  }

  if (digitalRead(BTN_START) == LOW) {
    motorState = !motorState;
    delay(300);
  }

  if (motorState) {
    analogWrite(ENA, speedPWM);

    if (direction) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      Serial.print("Forward | ");
    } else {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      Serial.print("Reverse | ");
    }
  } else {
    analogWrite(ENA, 0);
    Serial.print("STOP | ");
  }

  Serial.print("Speed: ");
  Serial.print(speedPercent);
  Serial.println("%");

  delay(200);
}
