#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeMonoBold9pt7b.h>

GxEPD2_3C<GxEPD2_213c, GxEPD2_213c::HEIGHT> display(GxEPD2_213c(/*CS=5*/ SS, /*DC=*/ 22, /*RST=*/ 21, /*BUSY=*/ 4));


void setup() {
  Serial.begin(115200);
  Serial.println("Ready to go");

  display.init();

  display.setRotation(1);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);

  const char HelloWorld[] = "Hello World!";

  // full window mode is the initial mode, set it anyway
  display.setFullWindow();
  display.fillScreen(GxEPD_WHITE);
  display.setCursor(0, 20);
  display.print(HelloWorld);

  display.setTextColor(GxEPD_YELLOW);
  display.setCursor(0, 60);
  display.print(HelloWorld);
  display.display(false); // full update
}


void loop() {}
