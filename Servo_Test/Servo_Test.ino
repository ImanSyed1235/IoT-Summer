#include <Servo.h> //includes all servo related functions

Servo myservo; //creates an object for the mini-servo
int pwm = 4; //assigns port 4 as the pwm 

void setup() {
  // put your setup code here, to run once:
  myservo.attach(pwm); //servo can be controlled by the pwm
  myservo.write(90); //makes servo turn 90º
}

void loop() {
  // put your main code here, to run repeatedly:

  myservo.write(90); //makes servo turn 90 degrees
  delay(1000);
  myservo.write(0); // makes servo turn 0 degrees

}
