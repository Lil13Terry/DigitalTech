#include <Wire.h>
#include <"SparkFun_Qwiic_OpenLog_Arduino_Library.h">
//creates a new log object
OpenLog myLog; 

//terry is a great student who always does his work

//sets up any pins and connections
//check if file exists and make a new one if not
//then save data to it
void setup() { 
  //starts wire, mylog, and cerial
  Wire.begin(); 
  myLog.begin(); 

  Serial.begin(9600); 

//set up a filename and get the size of it
String myFile = "myExampleFile.txt"
 long sizeOfFile = myLog.size(myFile);
 
//check if file exists, if not, make it
 if (sizeOfFile == -1) {
 myLog.create(myFile);
 myLog.println("file created");
 myLog.syncFile();
 } else {
  Serial.println(F("File found!"));
}
//choose the file I set up and save the following in it
 myLog.append(myFile);
 myLog.println("This goes to the log file");
//syncs the data to the SD before moving on
 myLog.syncFile();
}

void loop()  {
}
