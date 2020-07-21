#include <Adafruit_ILI9341.h>
#include <Adafruit_STMPE610.h>
#include <Adafruit_GFX.h>

#define STMPE_CS 16
#define TFT_CS 0
#define TFT_DC 15
#define SD_CS 2

#define BOXSIZE 40

#define TS_MINX 3800
#define TS_MAXX 100
#define TS_MINY 100
#define TS_MAXY 3750

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
Adafruit_STMPE610 ts = Adafruit_STMPE610(STMPE_CS);

/* We want to make a button that displays a text popup when pressed
 *  Ili9341 and Stmpe610 config
 *  Draw something for the GUI
 *  Code for getting touch points + displaying them
 */
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

//initialization
  if (!ts.begin()) {
    Serial.print("Error. TS could not begin");
    while(1);
  }
  tft.begin();

 //clear screen
  tft.fillScreen(ILI9341_BLACK);

  //creating button
  tft.fillRect(BOXSIZE, BOXSIZE, BOXSIZE * 4, BOXSIZE * 4, ILI9341_CYAN); 
  
  tft.setCursor(BOXSIZE * 1.625, BOXSIZE * 2.75);
  tft.setTextColor(ILI9341_DARKCYAN);
  tft.setTextSize(2.5);
  tft.println("PRESS HERE");

}

void loop() {
  // Recieve the point
  TS_Point p = ts.getPoint();

if (p.x < TS_MINX && p.x > TS_MAXX && p.y > TS_MINY && p.y < TS_MAXY) {

  p.x = map(p.x, TS_MINX, TS_MAXX, 0, tft.width());
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, tft.height());

  Serial.print("X = "); Serial.print(p.x);
  Serial.print("\tY = "); Serial.print(p.y);
  Serial.print("\tPressure = "); Serial.println(p.z); 

  if (BOXSIZE < p.y < BOXSIZE * 4 && BOXSIZE < p.x < BOXSIZE * 4) {
      tft.fillRect(BOXSIZE, BOXSIZE * 5, BOXSIZE * 5, BOXSIZE * 7, ILI9341_BLACK);
      tft.setCursor(BOXSIZE, BOXSIZE * 5.5);
      tft.setTextColor(ILI9341_CYAN);
      tft.setTextSize(2.5);
      Serial.println("Detected"); 
      tft.println("You pressed it"); 
      tft.setCursor(BOXSIZE, BOXSIZE * 6);
      tft.printf("X: %d | Y: %d", p.x, p.y);
      yield();
      delay(1000);
  }
  else {
    delay(1000);
  } 
}

  delay(500);

}
