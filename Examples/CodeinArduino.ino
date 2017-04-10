#include <Wire.h>
#define MPU 0x68
#define A_R 16384.0
#define G_R 131.0
#define RAD_A_DEG 57.295779
int16_t AcX, AcY, AcZ, GyX,GyY,GyZ;
float Acc[2];
float Gy[2];
float Angle[2];
unsigned long time;


void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
  time = 0.010;

}

void loop() {
  // put your main code here, to run repeatedly:
  gyroscopeFunction();
  delay(2000);
}

void gyroscopeFunction()
{
  Wire.beginTransmission(MPU);
  Wire.write(0x3B); //Pide el registro 0x3B - correspondiente
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,6,true);//A partir de 0x3B se piden 6 registros
  AcX = Wire.read()<<8|Wire.read();
  AcY = Wire.read()<<8|Wire.read();
  AcZ = Wire.read()<<8|Wire.read();
  //Calculo de los angulos a partir de la tangente:
  Acc[1] = atan(-1*(AcX/A_R)/sqrt(pow((AcY/A_R),2)+pow((AcZ/A_R),2)))*RAD_A_DEG;
  Acc[0] = atan((AcY/A_R)/sqrt(pow((AcX/A_R),2)+pow((AcZ/A_R),2)))*RAD_A_DEG;

  Wire.beginTransmission(MPU);
  Wire.write(0x43);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,4,true);
  GyX = Wire.read()<<8|Wire.read();
  GyY = Wire.read()<<8|Wire.read();

  //Cálculo del angulo del gyroscopio
  Gy[0] = GyX/G_R;
  Gy[1] = GyY/G_R;
  time = millis()-time;
  time = time/1000;
  //Filtro complementario
  Angle[0] = 0.98*(Angle[0]+Gy[0]*time)+0.02*Acc[0];
  Angle[1] = 0.98*(Angle[1]+Gy[1]*time)+0.02*Acc[1];
  time = millis();
  Serial.print("Angle X: ");Serial.print(Angle[0]);Serial.print("\n");
  Serial.print("Angle Y: ");Serial.print(Angle[1]);Serial.print("\n-------------\n");
  delay(1);
}
