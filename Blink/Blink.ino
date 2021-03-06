/*
  ESP8266 Blink by Simon Peter
  Blink the blue LED on the ESP-01 module
  This example code is in the public domain

  The blue LED on the ESP-01 module is connected to GPIO1
  (which is also the TXD pin; so we cannot use Serial.print() at the same time)

  Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/

int LED_Pin = 16;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(LED_Pin, OUTPUT);               //makes pin 16 an output
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // Turn the LED on (Note that LOW is the voltage level
  digitalWrite(LED_Pin, LOW);            // Turns off pin 16
  // but actually the LED is on; this is because
  // it is active low on the ESP-01)
  delay(1000);                      // Wait for a second
  digitalWrite(LED_BUILTIN, LOW);  // Turn the LED off by making the voltage HIGH
  digitalWrite(LED_Pin, HIGH);           // Turns on pin 16
  delay(1000);                      // Wait for two seconds (to demonstrate the active low LED)
}
