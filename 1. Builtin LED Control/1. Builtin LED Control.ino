/* Arduino Built In LED Blink

   GitHub URL - https://github.com/narayanvyas/IoT-workshop

   Components
   ----------
    - Arduino Uno R3

*/

/* Method Documentation

  setup - The setup() function is called when a sketch starts. Use it to initialize variables, pin modes, start using libraries, etc.
          The setup() function will only run once, after each powerup or reset of the Arduino board.

  loop - After creating a setup() function, which initializes and sets the initial values, the loop() function does precisely what its name suggests, and loops consecutively, allowing your program to change and respond.

  pinMode - Configures the specified pin to behave either as an input or an output. It takes two arguments
            First arguments tells the name of pin, and second argument tells the type of pin, either INPUT or OUTPUT

  digitalWrite - Write a HIGH or a LOW value to a digital pin. It takes two arguments
                 First arguments tells the name of pin, and second argument tells the state of pin, either HIGH or LOW

  delay - Pauses the program for the amount of time (in milliseconds) specified as parameter. (There are 1000 milliseconds in a second.)
*/

void setup() {
  pinMode(LED_BUILTIN , OUTPUT); // Setting LED as Output Device
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // Turning LED On
  delay(500); // Setting Delay of 1/2 Second
  digitalWrite(LED_BUILTIN, LOW);  // Turning LED Off
  delay(500); // Setting Delay of 1/2 Second
}