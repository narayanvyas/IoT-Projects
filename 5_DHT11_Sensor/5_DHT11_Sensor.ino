/*  DHT11 Sensor
 *   
 *  GitHub URL - https://github.com/narayanvyas/IoT-Projects
 * 
 *  
 * Components
 * ----------
 *  - Arduino Uno
 *  - DHT11
 *  - jumper wires
 *  - Breadboard
 *  
 *  Libraries
 *  ---------
 *  - Unified Sensor - https://github.com/adafruit/Adafruit_Sensor
 *
 * Connections
 * -----------
 *
 *      DHT       |    Arduino Uno
 *  -----------------------------
 *      1         |      5V  (Left Pin Number 1)
 *      2         |      13 (Digital Pin 13 On Arduino)
 *      3         |      Unplugged
 *      4         |      GND
 *      
 * For the DHT22:
 * 
 *  * Hold the sensor so that the grill is towards you. Here are the connections
 * 
 *     -----------
 *     | - |  -  |
 *     | - |  -  |
 *     | - |  -  |
 *     | - |  -  |
 *     -----------
 *     |  |  |  |
 *     |  |  |  |
 *     |  |  |  |
 *     |  |  |  |
 *    5V  2     GND
 *      data
 * 
 * Other information
 * -----------------
 *  For information on the LiquidCrystal library: https://www.arduino.cc/en/Reference/LiquidCrystal
 * 
 */

#include "DHT.h"

#define DHTPIN 13      // what pin we're connected to
#define DHTTYPE DHT11  // DHT 11  (AM2302)
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  delay(500);
  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    Serial.print("Waiting...");
    lcd.println(" from DHT");

  } else {
    Serial.print("Temp: ");
    Serial.print(t);
    Serial.println(" *C");
    Serial.print("Hum: ");
    Serial.print(h);
    Serial.println(" %");
    delay(5000);
  }
}