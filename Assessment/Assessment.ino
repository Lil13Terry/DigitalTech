// including libraries into code
#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <SparkFun_LPS25HB_Arduino_Library.h>

// helps to know the name of my log and my sensor
OpenLog SDLog;
LPS25HB SensorSD;
String filename = "TerrySensor.txt";
unsigned long TerrysTime = -99;
// runs code once   //HAN NOTES when does it run them once?
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
  SDLog.append(filename);
  SDLog.println("hPa,Temp, Millis");
  //HAN NOTES *hint* do you want to sync things now?
}
// loops code until arduino is turned off
void loop() {
   //HAN NOTES you should call your method here or it wont get run
  
} 

//HAN NOTES I would suggest that you want (boolean testing) and not () on the line below
void testMethod(){
  TerrysTime = millis();
  if (testing){
  // print sensors pressure and temperature
  Serial.print(SensorSD.getPressure_hPa());
  Serial.print(", ");
  Serial.println(SensorSD.getTemperature_degC());
  Serial.print(", ");
  Serial.println(TerrysTime);
  }else{
  SDLog.print(SensorSD.getPressure_hPa());
  SDLog.print(", ");
  SDLog.println(SensorSD.getTemperature_degC());
  SDLog.print(", ");
  SDLog.println(TerrysTime);
  //HAN NOTES *hint* do you want to sync things now?
  }
  delay(40);
}
