#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// -------- Keypad --------
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// -------- Pins --------
#define GREEN_LED 10
#define RED_LED 11
#define BUZZER 12

String password = "1234";
String input = "";

int attempts = 0;
bool locked = false;
unsigned long lockTime = 0;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ENTER PIN:");
}

void loop() {

  if (locked) {
    if (millis() - lockTime >= 10000) {
      locked = false;
      attempts = 0;
      lcd.clear();
      lcd.print("ENTER PIN:");
    }
    return;
  }

  char key = keypad.getKey();

  if (key) {

    if (key >= '0' && key <= '9') {
      input += key;

      lcd.setCursor(input.length()-1,1);
      lcd.print("*");
    }

    if (input.length() == 4) {

      if (input == password) {

        lcd.clear();
        lcd.print("ACCESS");
        lcd.setCursor(0,1);
        lcd.print("GRANTED");

        digitalWrite(GREEN_LED, HIGH);
        delay(3000);
        digitalWrite(GREEN_LED, LOW);

      } else {

        lcd.clear();
        lcd.print("ACCESS");
        lcd.setCursor(0,1);
        lcd.print("DENIED");

        digitalWrite(RED_LED, HIGH);

        tone(BUZZER,1000);
        delay(1000);
        noTone(BUZZER);

        digitalWrite(RED_LED, LOW);

        attempts++;

        if(attempts>=3){

          locked=true;
          lockTime=millis();

          lcd.clear();
          lcd.print("LOCKED");
          lcd.setCursor(0,1);
          lcd.print("WAIT 10 SEC");
        }

      }

      input="";

      if(!locked){
        delay(1500);
        lcd.clear();
        lcd.print("ENTER PIN:");
      }

    }

  }

}
