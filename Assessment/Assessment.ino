#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"
#include <SparkFun_LPS25HB_Arduino_Library.h>

// WHATS THIS DO?
OpenLog bigLog;
LPS25HB SensorSensor;

// WHATS THIS DO?
const byte OpenLogAddress = 42;

// WHATS THIS DO?
void setup() {
  // WHATS THIS DO?
  Serial.begin(9600);
  Wire.begin();
  SensorSensor.begin();
  bigLog.begin();

  
  // if sensor is not connected, print line "LPS25HB disconnected. Reset the board to try again."
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
