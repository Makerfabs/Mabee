#include<DHT.h>
DHT  dht(5,DHT11);



void setup() {
  Serial.begin(115200);
  Serial.println("DHT11 TEST");
    dht.begin();
    
}

void loop() {

  float t = dht.readTemperature();
  float h = dht.readHumidity();
  Serial.print("T=");
  Serial.println(t,2);
  Serial.print("H=");
  Serial.println(h,2);

 
  delay(2000);
}
