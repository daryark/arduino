#include <Servo.h>  // Include the Servo library

#define SENSOR_LEFT A0   // Left sensor connected to A0
#define SENSOR_RIGHT A1  // Right sensor connected to A1
#define SENSOR_DOWN A2   // Down sensor connected to A2

#define SERVO_HORIZONTAL_PIN 8  // Horizontal servo connected to pin 9
#define SERVO_VERTICAL_PIN 9   // Vertical servo connected to pin 10

Servo servoHorizontal;  // Servo object for horizontal movement
Servo servoVertical;    // Servo object for vertical movement

int posHorizontal = 0;  // Initial position for horizontal servo
int posVertical = 0;    // Initial position for vertical servo

void setup() {
  servoHorizontal.attach(SERVO_HORIZONTAL_PIN);  // Attach horizontal servo to pin
  servoVertical.attach(SERVO_VERTICAL_PIN);      // Attach vertical servo to pin
  
  // Set the servos to start at mid position (90 degrees)
  servoHorizontal.write(posHorizontal);
  servoVertical.write(posVertical);

  Serial.begin(9600);  // Optional, for debugging
}

void loop() {
  int leftValue = analogRead(SENSOR_LEFT);    // Read light intensity from left sensor
  int rightValue = analogRead(SENSOR_RIGHT);  // Read light intensity from right sensor
  int downValue = analogRead(SENSOR_DOWN);    // Read light intensity from down sensor
  // Calculate the difference between left and right sensors for horizontal rotation
  int horizontalDiff = leftValue - rightValue;
  
  // If light is stronger on the left, move servo left; if on the right, move right
  if (abs(horizontalDiff) > 10) {  // Small threshold to avoid jitter
    if (horizontalDiff > 0 && posHorizontal > 0) {
      posHorizontal -= 1;  // Move left
    } 
    else if (horizontalDiff < 0 && posHorizontal < 180) {
      posHorizontal += 1;  // Move right
    }
    servoHorizontal.write(posHorizontal);  // Write new position to horizontal servo
  }

  // Calculate difference between down sensor and the average of left and right sensors for vertical rotation
  int avgHorizontal = (leftValue + rightValue) / 2;
  int verticalDiff = downValue - avgHorizontal;
  
  // If light is stronger downwards, move servo down; if above, move up
  if (abs(verticalDiff) > 10) {  // Threshold to avoid jitter
    if (verticalDiff > 0 && posVertical < 180) {
      posVertical += 1;  // Move down
    } 
    else if (verticalDiff < 0 && posVertical > 0) {
      posVertical -= 1;  // Move up
    }
    servoVertical.write(posVertical);  // Write new position to vertical servo
  }
  // Serial.print("R: " + String(rightValue) + " L: " + String(leftValue) + " D: " + String(downValue) + "    H: " + String(posHorizontal) + " V: " + String(posVertical) + "\n");
  delay(20);
}
