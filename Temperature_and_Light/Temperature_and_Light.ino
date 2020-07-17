#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

int bluePin = 5;
int greenPin = 2; 
int redPin = 16;
int c;

void setup() {
  // put your setup code here, to run once:

  dht.begin();
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
  analogWriteRange(30);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH);
  digitalWrite(redPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  delay(1000);
  float c = dht.readTemperature();
  Serial.println(c);
  analogWrite(redPin, 30-c);
  analogWrite(greenPin, c);
  
}
