#include<Servo.h>
int servoPin = 10;
int servoPos = 65;
Servo myServo;

void setup() {
  Serial.begin(100);
  myServo.attach(servoPin);

}


void loop() {
  myServo.write ( servoPos);
}