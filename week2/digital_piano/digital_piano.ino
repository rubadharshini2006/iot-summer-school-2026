/*
  Digital Piano using Buzzer
  Author: Rubadharshini
*/

const int buzzer = 8;
const int b1 = 2;
const int b2 = 3;
const int b3 = 4;
const int b4 = 5;
const int modeBtn = 6;

bool majorMode = true;

void setup() {
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);
  pinMode(b4, INPUT_PULLUP);
  pinMode(modeBtn, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
  Serial.println("Digital Piano Started");
}

void loop() {

  // Toggle Major/Minor mode
  if (digitalRead(modeBtn) == LOW) {
    majorMode = !majorMode;

    if (majorMode)
      Serial.println("Major Mode");
    else
      Serial.println("Minor Mode");

    delay(300);
  }

  bool btn1 = digitalRead(b1) == LOW;
  bool btn2 = digitalRead(b2) == LOW;
  bool btn3 = digitalRead(b3) == LOW;
  bool btn4 = digitalRead(b4) == LOW;

  // Two buttons pressed together -> Sol
  if ((btn1 + btn2 + btn3 + btn4) >= 2) {
    tone(buzzer, 392);
  }
  else if (btn1) {
    tone(buzzer, majorMode ? 262 : 247);
  }
  else if (btn2) {
    tone(buzzer, majorMode ? 294 : 277);
  }
  else if (btn3) {
    tone(buzzer, majorMode ? 330 : 311);
  }
  else if (btn4) {
    tone(buzzer, majorMode ? 349 : 330);
  }
  else {
    noTone(buzzer);
  }
}
