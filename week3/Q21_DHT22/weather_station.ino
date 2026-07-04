#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define RED_LED 3
#define GREEN_LED 4

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  // CSV Header
  Serial.println("timestamp,temp_C,temp_F,humidity");
}

void loop() {

  float tempC = dht.readTemperature();
  float humidity = dht.readHumidity();
  float tempF = tempC * 9.0 / 5.0 + 32.0;

  if (isnan(tempC) || isnan(humidity)) {
    Serial.println("Sensor Error");
    delay(2000);
    return;
  }

  // CSV Output
  Serial.print(millis());
  Serial.print(",");
  Serial.print(tempC);
  Serial.print(",");
  Serial.print(tempF);
  Serial.print(",");
  Serial.println(humidity);

  // LED Alert
  if (tempC > 35 || humidity > 80) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }

  delay(2000);
}
