#include <Servo.h>
#define SERVO 9
#define PH_LEFT A0
#define PH_RIGHT A2

Servo servo;

void setup() {
  servo.attach(SERVO);
  Serial.begin(9600);
}

int pos = 0;
int leftL = analogRead(PH_LEFT);
int rightL = analogRead(PH_RIGHT);

void loop() {
  int leftL = analogRead(PH_LEFT);
  int rightL = analogRead(PH_RIGHT);
  if (leftL > rightL)
  {
    // if (leftL - rightL < 5)
    //   return ;
    if (pos > 0)
      servo.write(--pos);
    // {
    //   pos+=5;
    //   Serial.println("left: " + String(leftL) + " right:  " + String(rightL) + "\n");
      // delay(200);
    // }
  }
  else if (rightL > leftL)
  {
    // if (rightL - leftL < 5)
    //   return ;
    if (pos < 180)
      servo.write(++pos);
    // {
    //   pos+=5;
    //   Serial.println("left: " + String(leftL) + " right:  " + String(rightL) + "\n");
      // delay(200);
    // }
  }
  delay(10);
}
