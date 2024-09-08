#define SWITCH_BTN 2
#define GREEN_LED 12
#define YELLOW_LED 8
#define RED_LED 13
void setup() {
  pinMode(SWITCH_BTN, INPUT_PULLUP); // Use internal pull-up for the button
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
}
unsigned long previous = 0;    // Tracks the last time the LEDs were toggled
const long interval = 1000;          // 1 second interval for blinking
void loop() {
  unsigned long current = millis(); // Get current time
  // Check if the button is not pressed
  if (digitalRead(SWITCH_BTN) == HIGH) {
    previous = 0; // gives fast reaction of YELLOW and RED after switch back
    // Button pressed, stop the blinking and turn all LEDs off
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, HIGH); // Keep GREEN LED on as an indicator
  } else {
    // Button pressed, continue blinking
    digitalWrite(GREEN_LED, LOW); // Turn GREEN LED off
    // Check if 1 second has passed to toggle the LEDs
    if (current - previous >= interval) {
      previous = current; // Update the last toggle time
      // Toggle RED and YELLOW LEDs
      digitalWrite(RED_LED, !digitalRead(RED_LED));   // Toggle RED LED
      digitalWrite(YELLOW_LED, !digitalRead(YELLOW_LED)); // Toggle YELLOW LED
    }
  }
}