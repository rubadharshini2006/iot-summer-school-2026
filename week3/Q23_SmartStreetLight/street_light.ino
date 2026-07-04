// Q23 - Smart Street Light (LDR + PIR)

#define LDR_PIN A0
#define PIR_PIN 2
#define LED_PIN 3

unsigned long motionTime = 0;

void setup() {
  Serial.begin(9600);

  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.println("Smart Street Light Started");
}

void loop() {

  int lightValue = analogRead(LDR_PIN);
  int motion = digitalRead(PIR_PIN);

  Serial.print("LDR: ");
  Serial.print(lightValue);
  Serial.print("   PIR: ");
  Serial.println(motion);

  // Night (Dark)
  if (lightValue < 500) {

    if (motion == HIGH) {

      analogWrite(LED_PIN, 255);
      motionTime = millis();

      Serial.println("[Night] Motion Detected - LED ON");
    }

    // LED ON for 30 seconds
    if (millis() - motionTime >= 30000) {

      analogWrite(LED_PIN, 51);   // 20% brightness

      Serial.println("[Night] No Motion - LED DIM");
    }

  }

  // Day
  else {

    analogWrite(LED_PIN, 0);

    Serial.println("[Day] LED OFF");
  }

  delay(500);
}
