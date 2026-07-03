/*
  Vending Machine State Machine
  Author: Rubadharshini

  State Diagram:
  IDLE -> COIN_INSERTED -> ITEM_SELECTED -> DISPENSING -> IDLE
  Cancel button returns to IDLE
*/

const int redLED = 2;
const int yellowLED = 3;
const int greenLED = 4;

const int coinBtn = 5;
const int selectBtn = 6;
const int cancelBtn = 7;

enum State {
  IDLE,
  COIN_INSERTED,
  ITEM_SELECTED,
  DISPENSING
};

State currentState = IDLE;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  pinMode(coinBtn, INPUT_PULLUP);
  pinMode(selectBtn, INPUT_PULLUP);
  pinMode(cancelBtn, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Current State: IDLE");
}

void loop() {

  if (digitalRead(cancelBtn) == LOW) {
    currentState = IDLE;
    Serial.println("State -> IDLE");
    delay(300);
  }

  switch (currentState) {

    case IDLE:
      digitalWrite(redLED, HIGH);
      digitalWrite(yellowLED, LOW);
      digitalWrite(greenLED, LOW);

      if (digitalRead(coinBtn) == LOW) {
        currentState = COIN_INSERTED;
        Serial.println("State -> COIN_INSERTED");
        delay(300);
      }
      break;

    case COIN_INSERTED:
      digitalWrite(redLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(greenLED, LOW);

      if (digitalRead(selectBtn) == LOW) {
        currentState = ITEM_SELECTED;
        Serial.println("State -> ITEM_SELECTED");
        delay(300);
      }
      break;

    case ITEM_SELECTED:
      digitalWrite(redLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(greenLED, HIGH);

      currentState = DISPENSING;
      Serial.println("State -> DISPENSING");
      delay(2000);
      break;

    case DISPENSING:
      digitalWrite(redLED, HIGH);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(greenLED, HIGH);

      Serial.println("Item Dispensed");
      delay(2000);

      currentState = IDLE;
      Serial.println("State -> IDLE");
      break;
  }
}
