#include <Servo.h> //includes all servo related functions

Servo miniServo; //creates an object for the mini-servo
int pwm = 4;

void setup() {
  // put your setup code here, to run once:
  miniServo.attach(pwm); //servo can be controlled by the pwm
  miniServo.write(90); //makes servo turn 90º
}

void loop() {
  // put your main code here, to run repeatedly:

  miniServo.write(90); //makes servo turn 90 degrees
  delay(1000);
  miniServo.write(0); // makes servo turn 0 degrees
  delay(1000);

}
