
int greenPin = 2; 
int redPin = 5;
int bluePin = 4;

void setup() {
  // put your setup code here, to run once:

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(bluePin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, HIGH);
  delay(1000);
  digitalWrite(bluePin, HIGH);
  digitalWrite(greenPin, HIGH);
  
  digitalWrite(redPin, LOW);
  digitalWrite(bluePin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(1000);
  digitalWrite(redPin, HIGH);
  digitalWrite(bluePin, HIGH);

  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, LOW);
  digitalWrite(bluePin, HIGH);
  delay(1000);
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, HIGH);
}
