#ifndef gyroscope_h
  #define gyroscope_h
  #include <Arduino.h>
  #include <Wire.h>
  #define MPU 0x68
  #define A_R 16384.0
  #define G_R 131.0
  class Gyroscope
  {
    public:
      Gyroscope();
      double getXangle();
      double getYangle();
      double getZangle();
    private:
      int16_t AcX, AcY, AcZ, GyX,GyY,GyZ;
      float Acc[2];
      float Gy[2];
      float Angle[2];
      double time;
  };
  #endif
