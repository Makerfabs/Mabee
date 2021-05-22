
#include <SPI.h>
#include <Simple_HCSR04.h>
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define MP_ESP32_SSD1306_I2C_ADDR 0x3C
#define MP_ESP32_SSD1306_WIDTH 128 // OLED display width, in pixels
#define MP_ESP32_SSD1306_HEIGHT 64 // OLED display height, in pixels
#define MP_ESP32_SSD1306_RST -1

#define MP_ESP32_I2C_SDA 4
#define MP_ESP32_I2C_SCL 5

Adafruit_SSD1306 display(MP_ESP32_SSD1306_WIDTH, MP_ESP32_SSD1306_HEIGHT, &Wire, MP_ESP32_SSD1306_RST);


#define ECHO_PIN 26 /// the pin at which the sensor echo is connected
#define TRIG_PIN 27 /// the pin at which the sensor trig is connected

// Define meter size as multiplier of 240 pixels wide 1.0 and 1.3333 work OK
//#define M_SIZE 1.3333
#define M_SIZE 2
Simple_HCSR04 *sensor;


const char union_text[] = "cm";

#define TFT_GREY 0x5AEB

float ltx = 0;                                   // Saved x coord of bottom of needle
uint16_t osx = M_SIZE * 120, osy = M_SIZE * 120; // Saved x & y coords
uint32_t updateTime = 0;                         // time for next update

int old_analog = -999; // Value last displayed

int value[6] = {0, 0, 0, 0, 0, 0};
int old_value[6] = {-1, -1, -1, -1, -1, -1};
int d = 0;

void setup(void)
{
  Serial.begin(115200); // For debug
  Wire.begin(4, 5);
  sensor = new Simple_HCSR04(ECHO_PIN, TRIG_PIN);

      if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    { // Address 0x3C for 128x32
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ; // Don't proceed, loop forever
    }
   
    display.clearDisplay();
    display.display();
 
}

void loop()
{

    unsigned long distance = sensor->measure()->cm();
    Serial.print("distance: ");
    Serial.print(distance);
    Serial.print("cm\n");
    display.clearDisplay();
          display.setTextSize(2);              // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE); // Draw white text
      display.setCursor(0, 0);             // Start at top-left corner
      display.print(distance);
      display.print("cm");
      display.display();

      delay(2000);
}
