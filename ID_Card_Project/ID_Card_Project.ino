#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "Image.h"

// For the Adafruit shield, these are the default.
#define TFT_DC 15
#define TFT_CS 0


// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

int x0;
int x1;
int y2;
int z0;
int w = tft.width();
int h = tft.height();


void setup() {
  tft.begin();
}

void loop() {
  tft.fillScreen(ILI9341_DARKCYAN);
  yield();

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
  yield();

  tft.drawRGBBitmap(45, 45, profileImage, IMAGE_WIDTH, IMAGE_HEIGHT);


  
  delay(1000000);
  
}
