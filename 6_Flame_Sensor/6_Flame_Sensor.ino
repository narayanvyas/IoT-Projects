/*  Flame Sensor
 *   
 *  GitHub URL - https://github.com/narayanvyas/IoT-Projects
 * 
 *  This code reads values from a Flame Sensor connected to an Arduino Uno.
 * 
 *  Components
 *  ----------
 *  - Arduino Uno
 *  - Flame Sensor
 *  - jumper wires
 *  - Breadboard
 *  
 *  Connections
 *  -----------
 *
 *      Flame Sensor  |    Arduino Uno
 *  ----------------------------------
 *      VCC           |      5V
 *      GND           |      GND
 *      Digital Out   |      2
 */

int flamePin = 2; // the pin connected to the digital flame sensor
bool flameDetected = false; // flag to indicate whether a flame is detected or not

void setup() {
  Serial.begin(9600); // initialize serial communication
  pinMode(flamePin, INPUT); // set the digital flame sensor pin as an input
}

void loop() {
  flameDetected = digitalRead(flamePin); // read the digital flame sensor value

  if (flameDetected) { // check if the flame is detected
    Serial.println("Flame detected!"); // print a message to the serial monitor
  } else {
    Serial.println("No flame detected."); // print a message to the serial monitor
  }
  delay(500); // wait for 500 milliseconds before checking again
}
