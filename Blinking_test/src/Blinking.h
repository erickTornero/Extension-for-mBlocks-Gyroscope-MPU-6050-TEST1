#ifndef blinking_h
  #define blinking_h
  #include <Arduino.h>
  class Blinking
  {
    public:
       Blinking(int pin);
       void setFrecuencyBlink(int frec);
     private:
       int _pin;
  };
#endif
