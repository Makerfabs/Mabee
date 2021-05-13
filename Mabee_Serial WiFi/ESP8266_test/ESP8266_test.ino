#include <SD.h>
#include <SPI.h>
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


void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    Wire.begin(MP_ESP32_I2C_SDA, MP_ESP32_I2C_SCL);
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    { // Address 0x3C for 128x32
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ; // Don't proceed, loop forever
    }
   
    display.clearDisplay();
    display.setTextSize(2);              // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE); // Draw white text
    display.setCursor(0, 0);             // Start at top-left corner
    display.println(F("Makerfabs"));
    display.display();
    delay(3000);
    
    display.clearDisplay();
    
}

void loop() {
   String text = "";

   Serial.print("AT\r\n");
   delay(1000);
   while(Serial.available())
   {
    delay(10);
    text = text + char(Serial.read());
    //Serial.print(text);
   if(!Serial.available()) 
   {  
      

      //Serial.println(text);
      display.clearDisplay();
      display.setTextSize(2);              // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE); // Draw white text
      display.setCursor(0, 0);             // Start at top-left corner
      display.print(text);
      display.display();
      }
    }   
    delay(2000);
    text = "";
    Serial.print("AT+GMR\r\n");
   delay(1000);
   while(Serial.available())
   {
    delay(10);
    text = text + char(Serial.read());
    //Serial.print(text);
   if(!Serial.available()) 
   {  
      

      //Serial.println(text);
      display.clearDisplay();
      display.setTextSize(1);              // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE); // Draw white text
      display.setCursor(0, 0);             // Start at top-left corner
      display.print(text);
      display.display();
      }
    }   
    
    while (1)  ;

}
