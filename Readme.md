## Arduino to SQL Temperature Logger

----

This would need some polish for sure to be truly useful.  The general idea is that an Arduino Board will read the readings from a temperature probe, then make an HTTP call to a web server which then dumps the data into a mySQL database.  The web server also has a basic page to display the temperatures in a table.

#### Quick and Dirty Set Up

What you need:

* An Arduino
* A Temperature Probe
* A webserver (I used a Raspberry Pi)
* A basic knowledge of how to use an Arduino and a web server and very basic code modifications.

#### The Basic Steps:

* Check the Arduino code  Several things need to be configured including the IP address of the server and the board itself.   
* Flash the Arduino with TemperatureProbeWebLogger.ino .  
* Connect the Temperature Probe to the board on pin 5.   
* Set up your webserver if needed with an SQL server and PHP.  
* Copy the web files to the web server.   This can be in a sub folder but you will need to include this in the Arduino code before flashing. 
* Edit dbconnect.php with your DB server information.
* Import the housetempsSCHEMA.sql into the database to create the basic database.
* Connect everything to the network.
* It should be working.