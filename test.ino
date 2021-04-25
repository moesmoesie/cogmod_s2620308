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
}

void loop() {
  float init_distance = usSensor.distanceCm();
  while(init_distance > 10){
    init_distance = usSensor.distanceCm();
    applyPower(80, 0);
  }

  applyPower(30, 0);
  delay(500);
  applyPower(-50,0);
  delay(700);
  applyPower(50,1);
  delay(600);
}
