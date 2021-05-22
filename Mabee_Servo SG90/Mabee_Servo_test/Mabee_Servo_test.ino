#include <Arduino.h>

int freq = 50;      // 频率(20ms周期)
int channel = 8;    // 通道(高速通道（0 ~ 7）由80MHz时钟驱动，低速通道（8 ~ 15）由 1MHz 时钟驱动。)
int resolution = 8; // 分辨率
const int led = 21;

int calculatePWM(int degree)
{ //0-180度
 //20ms周期，高电平0.5-2.5ms，对应0-180度角度
  const float deadZone = 6.4;//对应0.5ms（0.5ms/(20ms/256）)
  const float max = 32;//对应2.5ms
  if (degree < 0)
    degree = 0;
  if (degree > 180)
    degree = 180;
  return (int)(((max - deadZone) / 180) * degree + deadZone);
}

void setup()
{
  Serial.begin(9600);
  ledcSetup(channel, freq, resolution); // 设置通道
  ledcAttachPin(led, channel);          // 将通道与对应的引脚连接
}

void loop()
{
  
    ledcWrite(channel, calculatePWM(0)); // 输出PWM
    //Serial.printf("value=%d,calcu=%d\n", d, calculatePWM(d));
    delay(1000);
    ledcWrite(channel, calculatePWM(180)); 
    delay(1000);

}
