#define SWITCH_BTN 7
#define GREEN_LED 9
#define YELLOW_LED 10
#define RED_LED 11
void setup() {
  pinMode(SWITCH_BTN, INPUT_PULLUP);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  digitalWrite(GREEN_LED, HIGH);
}
unsigned long previous = 0;
const long interval = 2000;

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
      digitalWrite(YELLOW_LED, HIGH);
    if (current - previous >= interval) {
      previous = current;
      digitalWrite(YELLOW_LED, !digitalRead(YELLOW_LED));
      digitalWrite(RED_LED, !digitalRead(RED_LED));
    }
  }
}
