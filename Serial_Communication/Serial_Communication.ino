/*
 * RX and TX used to connect to USB; cannot use in code
 */

#include <SoftwareSerial.h>
SoftwareSerial mySerialPort(4, 5); 
//makes Rx and Tx two serial ports

char messageIn, messageOut; 
//creates the messageIn and messageOut variables to read/write


void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600); 
  //initialize serial communication in monitor
  mySerialPort.begin(9600); 
  //communication between serial monitor and Software serial pins

  
}

void loop() {
  // put your main code here, to run repeatedly:

  /*while I have data in the Software Serial buffer, I run this loop
   * ex. if I have "hello" I will run this loop 5 times
   * Reads the data from the Serial buffer
   */
  while(mySerialPort.available()) { 
 
    messageIn = mySerialPort.read(); 
    //reads each character + stores inside of messageIn variable
    Serial.print(messageIn); //prints each character
    delay(2); //gives computer time to process
  }

// while I have data in Serial buffer
  while(Serial.available()) {
    
    messageOut = Serial.read(); 
    mySerialPort.write(messageOut); //read in character to send it
    delay(2); //send the character + give computer time to process
  }
    

    
}
