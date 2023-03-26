/* PIR Motion Sensor
   GitHub URL - https://github.com/narayanvyas/Intruder-Alarm-System-Using-PIR-Motion-Sensor
   Components
   ----------
    - Arduino Uno R3
    - Infrared Motion Sensor
    - Two LEDs
    - Two 220 Ohm Resistors
    - A Buzzer
    - PCB
    - Wires
    - 9v Battery
    - 9v Battery Connector
    - On Off Switch
   Libraries
   ---------
   - None
   Connections
   -----------
        Break out          |     Arduino Uno
   --------------------------------------------
        PIR VCC            |        5V
        PIR GND            |        GND
        PIR OUT            |        3
        LED 1 OUT          |        9
        LED 2 OUT          |        11
        Buzzer OUT         |        13
        Buzzer GND         |        GND
     Also connect LEDs two 220 Ohm Resistors.
         ----/\/\/\/\----(LED |)----GND
*/

int inputPin = 3;       // choose the input pin (for PIR sensor)
int ledRed   = 6;     // choose the pin for Green LED
int ledGreen = 13;         // choose the pin for Red LED
int buzzer = 13;         // choose pin for the buzzer
int pirState = LOW;     // we start, assuming no motion detected
int val      = 0;       // variable for reading the pin status

//the time we give the sensor to calibrate (10-60 secs according to the datasheet)
int calibrationTime = 30; //This time is in seconds

void setup() {
  pinMode(ledRed, OUTPUT);      // declare Red LED as output
  pinMode(ledGreen, OUTPUT);      // declare Green LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  pinMode(buzzer, OUTPUT);     // declare buzzer as output

  Serial.begin(9600);
  Serial.println("Waiting for the sensor to warm up.");
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledGreen, HIGH);
  delay(600);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, LOW);
  delay(600);
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledGreen, HIGH);
  delay(600);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, LOW);
  delay(600);
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledGreen, HIGH);
  delay(600);
  Serial.println("SENSOR ACTIVE");
}

void loop() {
  val = digitalRead(inputPin);  // read input value

  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledGreen, LOW);  // turn Green LED OFF
    digitalWrite(ledRed, HIGH);  // turn Green LED ON
    tone(buzzer, 1000);
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
      delay(5000);
    }
  } else {
    digitalWrite(ledRed, LOW); // turn Red LED OFF
    digitalWrite(ledGreen, HIGH);  // turn Green LED ON
    if (pirState == HIGH) {
      // we have just turned off
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
      noTone(buzzer);
    }
  }
}