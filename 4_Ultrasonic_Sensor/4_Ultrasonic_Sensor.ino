/*  Ultrasonic Distance Sensor HC-SR04 With Servo Motor And LCD
 * 
 *  GitHub URL - https://github.com/narayanvyas/IoT-Projects
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - Ultrasonic Distance Sensor
 *
 *  Libraries
 *  ---------
 *  - None
 *
 * Connections
 * -----------
 *  Break out    |    Arduino Uno
 *  --------------------------------------------
 *      Ultrasonic VCC            |        5V
 *      Ultrasonic GND            |        GND
 *      Ultrasonic Echo           |        6
 *      Ultrasonic Trigger        |        7
 *      
 */


#define echoPin 6
#define trigPin 7

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.print("Distance is: ");
  Serial.print(distance);
  Serial.println(" CM");
}