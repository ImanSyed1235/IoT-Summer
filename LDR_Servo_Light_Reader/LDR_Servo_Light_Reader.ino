/*
 * Connect the LDR
 * Read the ambient light
 * Represent the angle using the servo
 */
 
#include <Servo.h>

int pwm = 4;
int ldrPin = A0;
int analogValue = 0;
Servo miniServo; 

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  miniServo.attach(pwm);
  miniServo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogValue = analogRead(ldrPin);
  Serial.println(analogValue);
  analogValue = map(analogValue, 50, 200, 0, 180);
  miniServo.write(analogValue);
  delay(1000);
  
}
