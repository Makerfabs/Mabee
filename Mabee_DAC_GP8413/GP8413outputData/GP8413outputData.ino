/*!
  * @file GP8413outputData.ino
  * @brief Set the output channels, voltage values, and range to convert the I2C signal into two channels of analog voltage signals ranging from 0-5V or 0-10V.
  * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @license     The MIT License (MIT)
  * @author      [fary](feng.yang@dfrobot.com)
  * @version  V1.0
  * @date  2023-05-10
  * @url https://github.com/DFRobot/DFRobot_GP8XXX
  */
#include <Wire.h>
#include "DFRobot_GP8XXX.h"
/**************************
----------------------------
| A2 |  A1 | A0 | i2c_addr |
----------------------------
| 0  |  0  | 0  |   0x58   |
----------------------------
| 0  |  0  | 1  |   0x59   |
----------------------------
| 0  |  1  | 0  |   0x5A   |
----------------------------
| 0  |  1  | 1  |   0x5B   |
----------------------------
| 1  |  0  | 0  |   0x5C   |
----------------------------
| 1  |  0  | 1  |   0x5D   |
----------------------------
| 1  |  1  | 0  |   0x5E   |
----------------------------
| 1  |  1  | 1  |   0x5F   |
----------------------------
***************************/
//DFRobot_GP8413 GP8413(/*deviceAddr=*/0x59);

DFRobot_GP8XXX_IIC GP8413(RESOLUTION_15_BIT, 0x59, &Wire);

#define I2C_SCL 39
#define I2C_SDA 38

// range is 0~10000mv
void setDacVoltage(uint16_t vol, uint8_t ch) {
    uint16_t setting_vol = 0;
    if (vol > 10000) {
        vol = 10000;
    }
    if (ch > 1) ch = 1;
    setting_vol = (int16_t)((float)vol / 10000.0f * 32767.0f);
    if (setting_vol > 32767) {
        setting_vol = 32767;
    }
    GP8413.setDACOutVoltage(setting_vol, ch);
}


void setup() {

  Wire.begin(I2C_SDA, I2C_SCL);
  Serial.begin(115200);

  while(GP8413.begin()!=0){
    Serial.println(" Communication with the device failed. Please check if the connection is correct or if the device address is set correctly.");
    delay(1000);
  }

  /**
   * @brief Set the DAC output range.
   * @param range DAC output range.
   * @n     eOutputRange5V(0-5V)
   * @n     eOutputRange10V(0-10V)
   */	
  GP8413.setDACOutRange(GP8413.eOutputRange10V);
  
  /**
   * @brief Set different channel outputs for the DAC values.
   * @param data Data values corresponding to voltage levels.
   * @n With a 15-bit precision DAC module, the data values ranging from 0 to 32767 correspond to voltage ranges of 0-5V or 0-10V, respectively.
   * @param channel Output channels.
   * @n  0:Channel 0.
   * @n  1:Channel 1.
   * @n  2:All channels.
   */  
  GP8413.setDACOutVoltage(0000,2);

  delay(1000);

  //Save the set voltage in the chip's internal memory for power loss recovery.
  //GP8413.store();
  Serial.println("Done");
}

void loop() {

  Serial.println("0V");
  setDacVoltage(0, 0);
  setDacVoltage(0, 1);
  delay(1000);

  Serial.println("1V");
  setDacVoltage(1000, 0);
  setDacVoltage(1000, 1);
  delay(1000);

  Serial.println("2V");
  setDacVoltage(2000, 0);
  setDacVoltage(2000, 1);
  delay(1000);

  Serial.println("3.3V");
  setDacVoltage(3300, 0);
  setDacVoltage(3300, 1);
  delay(1000);

  Serial.println("4.4V");
  setDacVoltage(4400, 0);
  setDacVoltage(4400, 1);
  delay(1000);

  Serial.println("5.5V");
  setDacVoltage(5500, 0);
  setDacVoltage(5500, 1);
  delay(1000);

  Serial.println("6.6V");
  setDacVoltage(6600, 0);
  setDacVoltage(6600, 1);
  delay(1000);

  Serial.println("7.7V");
  setDacVoltage(7700, 0);
  setDacVoltage(7700, 1);
  delay(1000);

  Serial.println("8.8V");
  setDacVoltage(8800, 0);
  setDacVoltage(8800, 1);
  delay(1000);

  Serial.println("9.9V");
  setDacVoltage(9900, 0);
  setDacVoltage(9900, 1);
  delay(1000);

  Serial.println("10V");
  setDacVoltage(10000, 0);
  setDacVoltage(10000, 1);
  delay(1000);
}
