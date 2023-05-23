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

  
  // WHATS THIS DO?
  if (SensorSensor.isConnected() == false) {
    Serial.println("LPS25HB disconnected. Reset the board to try again.");
  }
// WHATS THIS DO?
  bigLog.append("appendMe.txt");
  bigLog.println("This is recorded to appendMe.txt");
}
// WHATS THIS DO?
void loop() {
  // WHATS THIS DO?
  Serial.print(SensorSensor.getPressure_hPa());
  Serial.print(", ");
  Serial.println(SensorSensor.getTemperature_degC());
// WHATS THIS DO?
  delay(40);
}
