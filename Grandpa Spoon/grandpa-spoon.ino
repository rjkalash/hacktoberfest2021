#include<SPI.h>
#include<Wire.h>
#include<Servo.h>
#define MPU 0x68  
Servo ServoX, ServoY;
double AcX, AcY, AcZ;
int Pitch, Roll;
void setup()
{
	ServoX.attach(3);
  	init_MPU(); 
}
void loop()
{
	FunctionsMPU(); 
  	Roll = FunctionsPitchRoll(AcX, AcY, AcZ);   
  	int ServoRoll = map(Roll, -75, 75, 0, 180);
  	ServoX.write(ServoRoll);
  	Serial.print("Roll: "); 
	Serial.print(Roll);
  	Serial.print("\n");
}
void init_MPU()
{
	Wire.begin();
  	Wire.beginTransmission(MPU);
  	Wire.write(0x6B);  
  	Wire.write(0);     
  	Wire.endTransmission(true);
  	delay(1000);
}
double FunctionsPitchRoll(double A, double B, double C)
{
	double DataA, DataB, Value;
  	DataA = A;
  	DataB = (B * B) + (C * C);
  	DataB = sqrt(DataB);
  	Value = atan2(DataA, DataB);
  	Value = Value * (180 / 3.14);
  	return (int)Value;
}
void FunctionsMPU()
{
	Wire.beginTransmission(MPU);
  	Wire.write(0x3B);  
  	Wire.endTransmission(false);
  	Wire.requestFrom(MPU, 6, true);  
  	AcX = Wire.read()<<8 | Wire.read();       
  	AcY = Wire.read()<<8 | Wire.read();  
  	AcZ = Wire.read()<<8 | Wire.read();  
}