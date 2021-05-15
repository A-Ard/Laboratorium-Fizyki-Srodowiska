#include <Time.h>
#include <TimeLib.h>

#include <SPI.h>
#include <SD.h>


int ReadAmb = A0;
int ReadUV = A1;

File myFile;




void setup() {
  pinMode(ReadUV, INPUT);
  pinMode(ReadAmb, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600); //open serial port, set the baud rate to 9600 bps
  Serial.println("Starting up...");
  // Open serial communications and wait for port to open:



  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.

 
}


void loop() 
{
      int uvLevel = averageAnalogRead(ReadUV);
      int ambLevel = averageAnalogRead(ReadAmb);

      float outVoltUV = 5.0 * uvLevel/1024;
      float outVoltAmb = 5.0 * ambLevel/1024;
      float uvIntensity = mapfloat(outVoltUV, 0.99, 2.9, 0.0, 15.0);
      float ambDensity = mapfloat(outVoltAmb, 0.00, 5.0, 0.0, 1000.0);
      
      myFile = SD.open("data.txt", FILE_WRITE);

      
      time_t t = now();
      myFile.println(hour(t));
      myFile.println(minute(t));
      myFile.println(second(t));

      myFile.println();
      
      myFile.println("UVAnalogOutput: ");
      myFile.println(uvLevel);

      myFile.println(" OutputVoltage: ");
      myFile.println(outVoltUV);

      myFile.println(" UV Intensity: ");
      myFile.println(uvIntensity);
      myFile.println(" mW/cm^2");

      myFile.println();

      myFile.println("AmbientAnalogOutput: ");
      myFile.println(ambLevel);

      myFile.println(" OutputVoltage: ");
      myFile.println(outVoltAmb);

      myFile.println(" Ambient Density: ");
      myFile.println(ambDensity);
      myFile.println(" lux");

      myFile.println();

      myFile.close();
      digitalWrite(13, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
      delay(4000);
      
}
//Takes an average of readings on a given pin
//Returns the average

  int averageAnalogRead(int pinToRead)
  {
  byte numberOfReadings = 8;
  unsigned int runningValue = 0;

  for(int x = 0 ; x < numberOfReadings ; x++)
    runningValue += analogRead(pinToRead);
  runningValue /= numberOfReadings;

  return(runningValue);
  }


//The Arduino Map function but for floats
//From: http://forum.arduino.cc/index.php?topic=3922.0
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max){

  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
