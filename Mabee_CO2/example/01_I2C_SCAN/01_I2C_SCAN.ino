#include <Wire.h>


#define I2C_SDA_PIN 2
#define I2C_SCL_PIN 3

//#define I2C_SDA_PIN 4
//#define I2C_SCL_PIN 5
void setup()
{
  Wire.begin(I2C_SDA_PIN,I2C_SCL_PIN);
  Wire.setClock(100000UL);
  Serial.begin(115200);
  Serial.println("nI2C Scanner 100Khz");
}
void loop()
{
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  delay(1000);
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    Wire.beginTransmission(address);
    delay(100);
    error = Wire.endTransmission();
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
      nDevices++;
      delay(1000);
    }
    else if (error==4)
    {
      Serial.print("Unknow error at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }   
  }
  if (nDevices == 0)
    Serial.println("No I2C devices founded");
  else
    Serial.println("done!");
  delay(5000);           // wait 5 seconds for next scan
}
