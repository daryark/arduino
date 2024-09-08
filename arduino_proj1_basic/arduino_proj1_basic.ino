#define SWITCH_BTN 2
#define GREEN_LED 12
#define YELLOW_LED 8
#define RED_LED 13
void setup() {
  pinMode(SWITCH_BTN, INPUT_PULLUP);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
}
unsigned long previous = 0;
const long interval = 1000;
void loop() {
  unsigned long current = millis();
  if (digitalRead(SWITCH_BTN) == HIGH) {
    previous = 0;
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  } else {
    digitalWrite(GREEN_LED, LOW);
    if (current - previous >= interval) {
      previous = current;
      digitalWrite(RED_LED, !digitalRead(RED_LED));
      digitalWrite(YELLOW_LED, !digitalRead(YELLOW_LED));
    }
  }
}