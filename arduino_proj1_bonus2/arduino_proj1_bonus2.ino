#define SWITCH_BTN 2
#define GREEN_LED 12
#define YELLOW_LED 8
#define RED_LED 13
void setup() {
  pinMode(SWITCH_BTN, INPUT_PULLUP);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  digitalWrite(GREEN_LED, HIGH);
}
unsigned long previous = 0;
const long intervalRed = 500;
const long intervalYellow = 2000;

void loop() {
  unsigned long current = millis();
  if (digitalRead(SWITCH_BTN) == HIGH) {
    previous = 0;

    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  } else {
    digitalWrite(GREEN_LED, LOW);
    if (!digitalRead(RED_LED) && !digitalRead(YELLOW_LED))
      digitalWrite(RED_LED, HIGH);
    if ((current - previous >= intervalRed && digitalRead(RED_LED)
      || (current - previous >= intervalYellow && digitalRead(YELLOW_LED)))) {
      previous = current;
      digitalWrite(YELLOW_LED, !digitalRead(YELLOW_LED)); 
      digitalWrite(RED_LED, !digitalRead(RED_LED));
    }
  }
}