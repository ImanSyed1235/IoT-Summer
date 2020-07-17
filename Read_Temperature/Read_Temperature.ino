#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("DHTxx test!")); 

  dht.begin();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  float c = dht.readTemperature(); //temp in celcius
  float f = dht.readTemperature(true); //temp in fahrenheit
  Serial.print(F("Temperature: ")); 
  Serial.print(c);
  Serial.print(F("ºC "));
  Serial.print(f);
  Serial.print(F("ºF \n")); 
}
