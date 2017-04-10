#include "Gyroscope.h"
Gyroscope::Gyroscope()
{
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  time = 0.010;
}
double Gyroscope::getXangle()
{
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,6,true);
  AcX = Wire.read()<<8|Wire.read();
  AcY = Wire.read()<<8|Wire.read();
  AcZ = Wire.read()<<8|Wire.read();
  //Cálculo de los angulos
  Acc[1] = atan(-1*(AcX/A_R)/sqrt(pow((AcY/A_R),2)+pow((AcZ/A_R),2)))*RAD_A_DEG);
  Acc[0] = atan((AcY/A_R)/sqrt(pow((AcX/A_R),2)+pow((AcZ/A_R),2)))*RAD_A_DEG;

  Wire.beginTransmission(MPU);
  Wire.write(0x43);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,4,true);
  GyX = Wire.read()<<8|Wire.read();
  GyY = Wire.read()<<8|Wire.read();

  Angle[0] = 0.98*(Angle[0]+Gy[0]*time)+0.02*Acc[0];
  Angle[1] = 0.98*(Angle[1]+Gy[1]*time)+0.02*Acc[1];
  return Angle[0];
}
double Gyroscope::getYangle()
{
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,6,true);
  AcX = Wire.read()<<8|Wire.read();
  AcY = Wire.read()<<8|Wire.read();
  AcZ = Wire.read()<<8|Wire.read();
  //Cálculo de los angulos
  Acc[1] = atan(-1*(AcX/A_R)/sqrt(pow((AcY/A_R),2)+pow((AcZ/A_R),2)))*RAD_A_DEG);
  Acc[0] = atan((AcY/A_R)/sqrt(pow((AcX/A_R),2)+pow((AcZ/A_R),2)))*RAD_A_DEG;

  Wire.beginTransmission(MPU);
  Wire.write(0x43);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,4,true);
  GyX = Wire.read()<<8|Wire.read();
  GyY = Wire.read()<<8|Wire.read();

  Angle[0] = 0.98*(Angle[0]+Gy[0]*time)+0.02*Acc[0];
  Angle[1] = 0.98*(Angle[1]+Gy[1]*time)+0.02*Acc[1];
  return Angle[1];
}
double Gyroscope::getZangle()
{
  return 0.0;
}
