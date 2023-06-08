// including libraries into code
#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"
#include <SparkFun_LPS25HB_Arduino_Library.h>

// helps to know the name of my log and my sensor
OpenLog SDLog;
LPS25HB SensorSD;

// runs code once
void setup() {
  //  writing terminal at a data rate of 9600bps
  Serial.begin(9600);
  // calls the wire library 
  Wire.begin();
  //  starts up my log and my sensor
  SensorSD.begin();
  SDLog.begin();

  
  // if sensor is not connected, print line "SensorSD hasn't worked, reset board and retry
  if (SensorSD.isConnected() == false) {
    Serial.println("SensorSD hasn't worked, reset board and retry");
  }
// attaches text file to log, once doing that it prints line "This is recorded to appendMe.txt"
  SDLog.append("appendMe.txt");
  SDLog.println("Time,hPa,Total");
}
// loops code until arduino is turned off
void loop() {
  // print sensors pressure and temperature
  Serial.print(SensorSD.getPressure_hPa());
  Serial.print(", ");
  Serial.println(SensorSD.getTemperature_degC());
// delays the code by 40 milliseconds
  delay(40);
}
//HAN NOTES I would look at making some methods to help make your code purpose clearer
//HAN NOTES a suggestion would be one to setup the sdcard and another to take and write sensor readings
