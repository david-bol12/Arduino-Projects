#include <Servo.h>

Servo myservo;
const int OPEN_ANGLE = 80;
const int CLOSE_ANGLE = 165;

void setup() {
  pinMode(11, OUTPUT);
  pinMode(12, INPUT);
  myservo.attach(11);
}

int y = 0;
int val = CLOSE_ANGLE;

void loop() {
  myservo.write(val);
  if(digitalRead(12) == HIGH) {
    y = 1;
  }
  if(digitalRead(12) == LOW && y == 1) {
    y = 0;
    if(val == OPEN_ANGLE) {
      val = CLOSE_ANGLE;
    } else {
      val = OPEN_ANGLE;
    }
  }
}
