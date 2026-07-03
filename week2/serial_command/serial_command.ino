/*
  Serial Command Interface
  Author: Rubadharshini
*/

int blinkCounter = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter Commands:");
}

void loop() {

  if (Serial.available()) {

    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "LED_ON") {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("LED ON");
    }

    else if (cmd == "LED_OFF") {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("LED OFF");
    }

    else if (cmd.startsWith("BLINK_")) {

      int n = cmd.substring(6).toInt();

      if (n >= 1 && n <= 9) {

        for (int i = 0; i < n; i++) {
          digitalWrite(LED_BUILTIN, HIGH);
          delay(500);
          digitalWrite(LED_BUILTIN, LOW);
          delay(500);
        }

        blinkCounter += n;
        Serial.println("Blink Completed");
      }
      else {
        Serial.println("ERROR: Invalid Blink Count");
      }
    }

    else if (cmd == "STATUS") {
      Serial.print("LED State: ");
      Serial.println(digitalRead(LED_BUILTIN));

      Serial.print("Blink Counter: ");
      Serial.println(blinkCounter);
    }

    else if (cmd == "RESET") {
      blinkCounter = 0;
      Serial.println("Blink Counter Reset");
    }

    else {
      Serial.println("ERROR: Unknown command");
    }
  }
}
