#include "Blinking.h"
Blinking::Blinking(int pin)
{
  pinMode(pin,OUTPUT);
  _pin = pin;
}
void Blinking::setFrecuencyBlink(int freq)
{
  for(int i=0;i<10;i++)
  {
    digitalWrite(_pin,1);
    delay(2000);
    digitalWrite(_pin,0);
    delay(2000);
  }
  for(int i=0;i<10;i++)
  {
    digitalWrite(_pin,1);
    delay(200);
    digitalWrite(_pin,0);
    delay(200);
  }

}
