#include <Arduino.h>

void setup();
void loop();
#line 1 "src/sketch.ino"
void setup()
{
	pinMode(12,OUTPUT);
}

void loop()
{
  digitalWrite(12,HIGH);
  delayMicroseconds(13);
  digitalWrite(12,LOW);
  delayMicroseconds(13);
}
