	
#include <SPI.h>
#include <Ethernet.h> // Used for Ethernet
#include "dht.h"

dht DHT;

define DHT11_PIN 5 //  Pin or Temperature Probe


// **** ETHERNET SETTING ****
// Arduino Uno pins: 10 = CS, 11 = MOSI, 12 = MISO, 13 = SCK
// Ethernet MAC address - must be unique on your network - MAC Reads T4A001 in hex (unique in your network)
byte mac[] = { 0x54, 0x34, 0x41, 0x30, 0x30, 0x31 }; // This can be changed to anything if needed                    
// For the rest we use DHCP (IP address and such)
byte ip[] = { 192, 168, 1, 80 }; // This Needs to be changed to match the local network

EthernetClient client;
char server[] = "IPADDRESS"; // IP Adres (or name) of server to dump data to

void setup() {

  Serial.begin(9600);
  Ethernet.begin(mac,ip);

  Serial.println("Tweaking4All.com - Temperature Drone - v2.0");
  Serial.println("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  Serial.print("IP Address        : ");
  Serial.println(Ethernet.localIP());
  Serial.print("Subnet Mask       : ");
  Serial.println(Ethernet.subnetMask());
  Serial.print("Default Gateway IP: ");
  Serial.println(Ethernet.gatewayIP());
  Serial.print("DNS Server IP     : ");
  Serial.println(Ethernet.dnsServerIP());
}

void loop() {
  
   const unsigned long fiveMinutes = 5 * 60 * 1000UL;
   static unsigned long lastSampleTime = 0 - fiveMinutes;  // initialize such that a reading is due the first time through loop()

   unsigned long now = millis();
   if (now - lastSampleTime >= fiveMinutes) {

    lastSampleTime += fiveMinutes;
    // READ DATA
    Serial.print("DHT11, \t");
    int chk = DHT.read11(DHT11_PIN);
    switch (chk)
    {
      case DHTLIB_OK:  
		Serial.print("OK,\t"); 
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
    
    // if you get a connection, report back via serial:
    if (client.connect(server, 80)) {
      Serial.println("-> Connected");
      // Make a HTTP request:
      client.print( "GET /add_data.php?"); // If you use a subdirectory you will need to add it to this URL
      client.print("serial=");
      client.print( "Probe1" );
      client.print("&");
      client.print("temperature=");
      client.print(DHT.temperature,1);
//      client.print("88");
      client.print("&");
      client.print("humid=");
      client.print(DHT.humidity,1);
//      client.print("88");
      client.println( " HTTP/1.1");
      client.print( "Host: " );
      client.println(server);
      client.println( "Connection: close" );
      client.println();
      client.println();
      client.stop();
    }
    else {
      // you didn't get a connection to the server:
      Serial.println("--> connection failed/n");
    }
    
  }
  
}
