#include <LiquidCrystal.h>
#define POT A0 //potentiometer pin
#define LED 9

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(LED, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

int prevPot = 0;
int currPot = 0;

int parseSerial()
{
  int input = Serial.parseInt();
  if (Serial.read() == '%')
    input = constrain(input, 0, 100) * 10.23 + 1;
  else
    input = constrain(input, 0, 1023);
  while (Serial.available()) //clean leftover chars
    Serial.read();
  return (input);
}

void  controller(int val)
{
  lcd.clear();
  lcd.print("LCD: " + String(val));
  lcd.setCursor(0,1);
  lcd.print("LED: " + String((int)(val / 10.23)) + "%");
  analogWrite(LED, map(val, 0, 1023, 0, 255));
}

void loop() {
  currPot = analogRead(POT);
  if (abs(currPot - prevPot) > 1)
  {
    prevPot = currPot;
    controller(currPot);
  }
  else if (Serial.available())
    controller(parseSerial());
  delay(100);
}
