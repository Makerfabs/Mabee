#include <Adafruit_NeoPixel.h>

#define PIN        21
#define NUMPIXELS 8

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  pixels.begin();
}
int i=0;
void loop() {
  if(i>7)  i=0;
  // put your main code here, to run repeatedly:
  pixels.setPixelColor(i, pixels.Color(0, 70, 0));
  pixels.show();
  delay(500);
  pixels.clear();
  i++;
  delay(500);
}
