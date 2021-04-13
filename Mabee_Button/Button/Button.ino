
void setup() {
  Serial.begin(115200);
  Serial.println("BUTTON TEST");
  pinMode(5,INPUT);   
}

void loop() {

  if(digitalRead(5)== LOW)
  {
    Serial.println("TRUE");
    delay(1000);
    }
   else
     {
    Serial.println("False");
    delay(500);
    }      
}
