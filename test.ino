#include <MeMCore.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

// Declaring the motor 
MeDCMotor rightMotor(10); // Find one motor in slot 9 and call it 
MeDCMotor leftMotor(9); // Find another motor in slot 10 and call it leftMotor
MeUltrasonicSensor usSensor(1); //Ultra sonic sensor on slot 1
const int basespeed = 10;

void applyPower(int power, int motor){
  power *= 2.55;
  switch(motor){
    case 0:
      rightMotor.run(power);
      leftMotor.run(-power);
      break;
    case 1:
      leftMotor.run(-power);
      break;
    case 2:
      rightMotor.run(power);
      break;
      
  }
}



void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
//  delay(1000);
//  leftMotor.run(100);
//  rightMotor.run(-100);
//  delay(1000);
//  leftMotor.run(10);
//  rightMotor.run(10);
}

void loop() {
//  leftMotor.run(-100);
//  applyPower(30, 0);
  float init_distance = usSensor.distanceCm();
  while(init_distance > 10){
    init_distance = usSensor.distanceCm();
    Serial.print(init_distance);
    applyPower(30, 0);
  }
  applyPower(15, 0);
  delay(2000);
  applyPower(0,0);
  delay(1000);
  applyPower(-30,0);
  delay(700);
  applyPower(20,1);
  delay(1000);
//  if(init_distance < 5){
//    applyPower(10, 0);
//    applyPower(30, 1);
//  }
  
  // put your main code here, to run repeatedly:
//  delay(1000);
  

}
