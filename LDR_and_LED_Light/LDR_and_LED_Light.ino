/* connect 2 LEDs on pins 4 and 5. 
 *  LED lights should turn on/off based on brightness levels
 *  (Brightness typiically varies between 300 and 600)
 *  300 - 400 --> no LEDs on
 *  400 - 500 --> one LED on
 *  500 - 600 --> both LEDs on
 */

int ldrPin = A0; 
int redPin = 5;
int greenPin = 4;
int analogValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogValue = analogRead(ldrPin);
  Serial.println(analogValue);
  if (analogValue < 400) {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    
  } else if (analogValue  >= 400 && analogValue <= 600) {
    
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
  } else {
        digitalWrite(redPin, HIGH);
        digitalWrite(greenPin, HIGH);
       }

    delay(100);
}
