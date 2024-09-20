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
unsigned long prevYellow = 0;
unsigned long prevRed = 0;
const long intervalRed = 500;
const long intervalYellow = 2000;

void loop() {
  unsigned long current = millis();
  if (digitalRead(SWITCH_BTN) == HIGH) {
    prevRed = 0;
    prevYellow = 0;

    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  } else {
    digitalWrite(GREEN_LED, LOW);
    if (current - prevRed >= intervalRed )
    {   
      prevRed = current;
      digitalWrite(RED_LED, !digitalRead(RED_LED));
      delay(100);
      digitalWrite(RED_LED, !digitalRead(RED_LED));

    }
    if (current - prevYellow >= intervalYellow ) {
      prevYellow = current;
      digitalWrite(YELLOW_LED, !digitalRead(YELLOW_LED));
      delay(100);
      digitalWrite(YELLOW_LED, !digitalRead(YELLOW_LED));

    }
  }
}
