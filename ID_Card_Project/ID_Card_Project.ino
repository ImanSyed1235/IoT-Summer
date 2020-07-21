#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Wire.h> 
#include <Adafruit_STMPE610.h>
#include "Image.h"
#include "NewImage.h"

// For the Adafruit shield, these are the default.
#define TFT_DC 15 //TFT Data/Clock (both in same line) --> multiplex
#define TFT_CS 0 //TFT Chip Select
#define STMPE_CS 16 //STMPE610 Chip Select
#define SD_CS 2 //STMPE610 

#define TS_MINX 3800
#define TS_MAXX 100
#define TS_MINY 100
#define TS_MAXY 3750


// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
Adafruit_STMPE610 ts = Adafruit_STMPE610(STMPE_CS);

int x0;
int x1;
int y2;
int z0;
int w = tft.width();
int h = tft.height();


void ID_Card() {
  tft.fillScreen(ILI9341_DARKCYAN);
  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(40, 20);
  tft.setTextSize(3);
  tft.println("Iman Syed");
  tft.setCursor(50, 250);
  tft.setTextSize(2);
  tft.println("Holton-Arms");
  tft.setCursor(40, 270);
  tft.println("Class of 2022");
  tft.fillRect(0, 0, 10, 320, 0xFFFF);
  tft.fillRect(0, 0, 240, 10, 0xFFFF);
  tft.fillRect(0, 310, 240, 320, 0xFFFF);
  tft.fillRect(230, 0, 240, 320, 0xFFFF);
  tft.drawRGBBitmap(45, 45, profileImage, IMAGE_WIDTH, IMAGE_HEIGHT); 
  yield();
}
void setup() {

  Serial.begin(115200);
  
  if (!ts.begin()) {
    Serial.print("Error");
    while(1);
  }
  tft.begin();
  Serial.print("Starting");
  
  ID_Card();
  
}

void loop() {

  TS_Point p = ts.getPoint();
  
  if (p.x < TS_MINX && p.x > TS_MAXX && p.y > TS_MINY && p.y < TS_MAXY) {

    p.x = map(p.x, TS_MINX, TS_MAXX, 0, tft.width());
    p.y = map(p.y, TS_MINY, TS_MAXY, 0, tft.height());
    Serial.print("\nDetected Point");


    if (240 > p.y && p.y > 45 && 191 > p.x && p.x > 45) {
      
      Serial.print("\nX = "); Serial.print(p.x);
      Serial.print("\tY = "); Serial.print(p.y);
      Serial.print("\tPressure = "); Serial.println(p.z); 
    
      tft.fillScreen(ILI9341_DARKCYAN);
      tft.drawRGBBitmap(10, 100, NewImage, newImage_Width, newImage_Height);
      delay(3000);
      ID_Card();
    }
    
  }

  delay(500);
  
  
}
