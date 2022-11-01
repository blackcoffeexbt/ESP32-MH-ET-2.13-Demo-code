#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeMonoBold9pt7b.h>

// DOESNT work vvv
//GxEPD2_3C<GxEPD2_213c, GxEPD2_213c::HEIGHT> display(GxEPD2_213c(/*CS=5*/ SS, /*DC=*/ 22, /*RST=*/ 21, /*BUSY=*/ 4));
GxEPD2_3C<GxEPD2_213c, GxEPD2_213c::HEIGHT> display(GxEPD2_213c(/*CS=5*/ SS, /*DC=*/ 22, /*RST=*/ 21, /*BUSY=*/ 4));
// WORKS vvvv
//GxEPD2_BW<GxEPD2_213_flex, GxEPD2_213_flex::HEIGHT> display(GxEPD2_213_flex(/*CS=5*/ SS, /*DC=*/ 22, /*RST=*/ 21, /*BUSY=*/ 4));


void setup() {
  Serial.begin(115200);
  //  WiFi.begin(wifiSSID, wifiPASS);
  //  while (WiFi.status() != WL_CONNECTED) {
  //     Serial.println("connecting");
  //     delay(500);
  //     }
  //
  Serial.println("connected");

  display.init();
//  display.setRotation(3);
//  display.setFont(&FreeSansBold12pt7b);


    display.setRotation(1);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);

  const char HelloWorld[] = "Hello World!";
//  int16_t tbx, tby; uint16_t tbw, tbh;
//  display.getTextBounds(HelloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
  // center bounding box by transposition of origin:
//  uint16_t x = ((display.width() - tbw) / 2) - tbx;
//  uint16_t y = ((display.height() - tbh) / 2) - tby;
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
