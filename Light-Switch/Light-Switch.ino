
int greenPin = 5; 
int redPin = 4;
int bluePin = 2;

void setup() {
  // put your setup code here, to run once:

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);


  /*
   * range for PWM cycle is 0-255
   * 0% = 0
   * 50% = 127
   */
  analogWriteRange(255); 
  
}

void loop() {
  // put your main code here, to run repeatedly:
  // 0 = LED with full brightness
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH); 
  digitalWrite(redPin, HIGH);

  
  for (int i = 255; i >= 0; i--) {
    analogWrite(greenPin, 255 - i);
    analogWrite(redPin, 255 - 3 * i);
    delay(20);
  }

  delay(1000);

  for (int j = 255; j >= 0; j--) {
    analogWrite(bluePin, 255 - j);
    analogWrite(greenPin, 255 - j);
    delay(20);
  }
  
}
