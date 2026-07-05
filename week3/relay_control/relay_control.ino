#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define RELAY_PIN 8
#define BUTTON_PIN 3

DHT dht(DHTPIN, DHTTYPE);

bool relayState = false;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  digitalWrite(RELAY_PIN, LOW);
}

void loop() {

  float temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("Failed to read sensor!");
    delay(1000);
    return;
  }

  // Manual Override
  if (digitalRead(BUTTON_PIN) == LOW) {
    relayState = !relayState;
    digitalWrite(RELAY_PIN, relayState);

    Serial.print("Manual Override -> Relay ");
    Serial.println(relayState ? "ON" : "OFF");

    delay(300);
  }

  // Automatic Control
  if (temp > 32) {
    relayState = true;
  }

  if (temp < 28) {
    relayState = false;
  }

  digitalWrite(RELAY_PIN, relayState);

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" C  Relay: ");

  if (relayState)
    Serial.println("ON");
  else
    Serial.println("OFF");

  delay(1000);
}
