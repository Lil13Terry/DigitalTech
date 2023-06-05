// including libraries into code
#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"
#include <SparkFun_LPS25HB_Arduino_Library.h>

// helps to know the name of my log and my sensor
OpenLog bigLog;
LPS25HB SensorSensor;

// runs code once
void setup() {
  //  writing terminal at a data rate of 9600bps
  Serial.begin(9600);
  // calls the wire library 
  Wire.begin();
  //  starts up my log and my sensor
  SensorSensor.begin();
  bigLog.begin();

  
  // if sensor is not connected, print line "LPS25HB disconnected. Reset the board to try again."
  //HAN NOTES How can you adjust this so that it starts a csv file? the first line of a csv are the headings for all subsequent lines
  if (SensorSensor.isConnected() == false) {
    Serial.println("LPS25HB disconnected. Reset the board to try again.");
  }
// attaches text file to log, once doing that it prints line "This is recorded to appendMe.txt"
  bigLog.append("appendMe.txt");
  bigLog.println("This is recorded to appendMe.txt");
}
// loops code until arduino is turned off
void loop() {
  // print sensors pressure and temperature
  Serial.print(SensorSensor.getPressure_hPa());
  Serial.print(", ");
  Serial.println(SensorSensor.getTemperature_degC());
// delays the code by 40 milliseconds
  delay(40);
}
//HAN NOTES I would look at making some methods to help make your code purpose clearer
//HAN NOTES a suggestion would be one to setup the sdcard and another to take and write sensor readings
