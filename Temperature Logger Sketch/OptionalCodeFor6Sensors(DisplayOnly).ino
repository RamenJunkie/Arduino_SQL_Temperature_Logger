
//
//    FILE: Six Sensor Temp/Humidity Probe.ino
//  AUTHOR: Josh Miller
// VERSION: 0.1.00
// PURPOSE: DHT library based sketch for multiple Temp/Hum probes on Arduino
//     URL: http://www.joshmiller.net
//
// Released to the public domain
//

#include "dht.h"

dht DHT;

void setup()
{
  Serial.begin(115200);
  Serial.println("Multi Sensor Temp/Humidity Readings");
  Serial.println("Version 1.0");
  Serial.println("Modified DHT Library Version");
  Serial.println("By Josh Miller, josh@lameazoid.com");
  Serial.println();
}

void loop()
{
  int i=1;
  
  
  while (i<7)
  {
    // READ DATA
    
    int chk = DHT.read11(i+1);
    switch (chk)
    {
      case DHTLIB_OK:  
		Serial.print("\t"); 
		break;
      case DHTLIB_ERROR_CHECKSUM: 
		Serial.print("Checksum error,\t"); 
		break;
      case DHTLIB_ERROR_TIMEOUT: 
		Serial.print("Time out error,\t"); 
		break;
      default: 
		Serial.print("Unknown error,\t"); 
  		break;
    }
    // DISPLAY DATA
    Serial.print("Probe ");
    Serial.print(i);
    Serial.print(" : Humidity is: ");
    Serial.print(DHT.humidity, 1);
    Serial.print(", Temperature is: ");
    Serial.print(DHT.temperature, 1);
    Serial.println(" C ");

    i++;
    delay(2000);
  }
  
}
//
// END OF FILE
//
