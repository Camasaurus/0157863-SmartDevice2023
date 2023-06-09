#include <SPI.h>  // SD Card module
#include <SD.h> // Also SD Card module
#include "RTClib.h"    // Real Time Clock (RTC) library
#include "Adafruit_NECremote.h"  // Infrared Remote library
#include <L298N.h>     // Motor Controller library
#include <Servo.h>     // Servo Motor library

// Outputs defined
#define ledRed A0     // Red traffic light LED, connected to pin A0
#define ledYellow A1  // Yellow traffic light LED, connected to pin A1
#define ledGreen A2   // Green traffic light LED, connected to pin A2
#define piezoPin 8    // Piezo Buzzer Pin

// Inputs defined
#define echoPin 6        //attach pin D2 Arduino to pin Echo of (Sonar Device) HC-SR04
#define trigPin A4       //attach pin D3 Arduino to pin Trig of (Sonar Device) HC-SR04
#define crashSensor 7    // Crash Sensor (button)
#define lineSensorPin 3  // Line Sensor (light)
#define IRpin 21        // IR Remote controller
#define pot A3           // Potentiometer device

// Real Time Clock (RTC)
RTC_Millis rtc;     // Software Real Time Clock (RTC)
DateTime rightNow;  // used to store the current time.

// IR Remote
Adafruit_NECremote remote(IRpin);

// DC Motor & Motor Module - L298N
// Pin definition 
const unsigned int IN1 = 7;
const unsigned int IN2 = 8;
const unsigned int EN = 9;
//Create one motor instance
L298N motor(EN, IN1, IN2);

//Servo
Servo myservo;

// SD Card - Confirm Pin
#define SDpin 53 //Arduino Megas have different pins set for SD Card initialisation than regular Arduinos.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Open serial communications and wait for port to open:
  while (!Serial) {
    delay(1);  // wait for serial port to connect. Needed for native USB port only
  }

  // SD Card initialisation
  Serial.print("Initializing SD card...");
  if (!SD.begin(SDpin)) {
    Serial.println("initialization failed!");
    while (1)
      ;
  }

  // Traffic Lights, modes set
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);

  // DC Motor & Motor Module - L298N, mode set
  motor.setSpeed(70);

  // Servo Motor, mode set
  myservo.attach(9);  //attaches the servo on pin 9 to the servo object.

  //Potentiometer, mode set
  pinMode(pot, INPUT);

  //Piezo, mode set
  pinMode(piezoPin, OUTPUT);

  //Sonar - HC-SR04, modes set
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output.
  pinMode(echoPin, OUTPUT);  // Sets the echoPin as an Output.

  //Line Sensor, mode set
  pinMode(lineSensorPin, OUTPUT);

  //Crash Sensor, mode set
  pinMode(crashSensor, INPUT);

  // Real Time Clock (RTC)
  rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
  Serial.println("initialization done.");
  logEvent("System Initialisation...");
}

void loop() {
  // put your main code here, to run repeatedly:
  lineSensorDebugMode();
  servoMotorMonitorSpeed();
  ingameProgressionThroughDCMotorMovement();
  potentiometerVolumeAdjust();
  trafficLightVisualDangerSystem();
  userInterfaceButton();
  infraredRemoteControllerInput();
  piezoBuzzerAlert();
  environmentalAlarmSystem();
  distanceSensorEnvironmentalCheck();
  Serial.println("All functions cycled");

  delay(1000); // Delay for 1 second, and then replay the loop() function again.
}

void lineSensorDebugMode() {
  /* 
  when the line sensor interacts with a pattern of lines, the sensor will determine if the user can access debug properties of the program.
  @params none
  @return lineSensorValue
*/
  int lineSensorValue = digitalRead(lineSensorPin);

  // Unfortunately due to time restraints, this function is unfinished, and does not provide any Output or Input.
}

void servoMotorMonitorSpeed() {
  /* 
  When the potentiometer is changedwhen the servo motor's state is changed, the speed of the program on the monitor will increase or decrease accordingly.
  @params Potentiometer state, line Sensor 'Debug' Privileges.
  @return none
*/
  int servoPos = 100;
  myservo.write(servoPos); //Changes the servo's position to the '100' value position, by writing a command to the servo using myservo.write to change it's position.
  
  // Unfortunately due to time restraints, this function is unfinished, and does not provide any Output or Input.
}

void ingameProgressionThroughDCMotorMovement() {
  /* 
  over time when the game is playing, the DC motor will move as a visual aid for the player on their progress. dependent on the elapsed time in the game, the difficulty may increase or "dangers" may appear.
  @params none
  @return none
*/
  motor.forward();
  delay(1000);
  motor.stop();
  delay(1000);
  motor.backward();
  delay(1000);

  // Unfortunately due to resource difficulties, this function is unfinished, and does not provide any Output or Input.
}

void potentiometerVolumeAdjust() {
  /* 
  when the potentiometer's state is changed, the volume of the program on the monitor will increase or decrease accordingly.
  @params line Sensor 'Debug Privileges'
  @return Potentiometer state
*/
  int potValue = analogRead(pot);
  //Serial.println(potValue);
  delay(500);

  // Unfortunately due to time restraints, this function is unfinished, and does not provide any Output or Input.
}

void trafficLightVisualDangerSystem() {
  /* 
  when the program receives "danger" variables from ingame "danger", the colour of the corresponding LED will turn on (red = high danger, yellow = medium danger, green = low danger)
  @params none
  @return none
  

  // Unfortunately due to technical difficulties, this function is unfinished, and does not provide any Output or Input.
  */
  digitalWrite(ledRed, HIGH);
  delay(500); // To try and get an output from the Traffic Light system, I tried to implement an LED to turn on and off every half a second, blinking essentially.
}

void userInterfaceButton() {
  /* 
  when the 'crash sensor' button is pressed, the user interface will progress to other options (and while in-game, will enable the pause menu/options)
  @params none
  @return crash sensor value
*/
  int crashSensorValue = digitalRead(crashSensor);
  
  if (crashSensorValue == HIGH) { // Detects when the light of the Crash Sensor's LED is low (off) or high (on).
    //Serial.println(crashSensorValue);
    logEvent("Button Activated"); // When the light of the crash sensor is on (the button is pressed), log the event and say "Button Activated"

    delay(1000);
    logEvent("Button Deactivated"); //After one second, say that the button has been deactivated.
  }

  // Unfortunately due to resource difficulties, this function is unfinished, and does not provide a consistent Output.
}

void infraredRemoteControllerInput() {
  /* 
  when the remote's (connected to the electronic board) presses specific buttons (inputs, ie. button 1,2,3,FUNC/STOP,VOLUME), specific outputs will occur.
  @params none
  @return infrared Remote Player Inputs
*/
  
  int c = remote.listen(1);  // waits 1 second before timing out!
  //int c = remote.listen();  // Without a number, it means 'wait forever'
  if (c >= 0) { // The variable 'c' is the number of the code recieved from a button pressed of an IR remote.

    switch (c) {
      // Top keys
    case 70: // case "70" means that if the code that comes through the IR Remote is 70, then log the event as UP, as 70 is the code recieved when the remote's UP button is pressed.
      logEvent("UP"); 
      break;
    case 21: // Similarly to case "70", case "21" logs the event as DOWN when the DOWN button on the IR remote is pressed.
      Serial.println("DOWN"); 
      break;
    case 68: 
      Serial.println("LEFT"); 
      break;
    case 67: 
      Serial.println("RIGHT"); 
      break;
    case 64: 
      Serial.println("OK"); 
      break;

      // Numbers
    case 22: 
      Serial.println("1");
      tone(piezoPin, 349);
      delay(100);
      noTone(piezoPin);
      break;
    case 25: 
      Serial.println("2"); 
      tone(piezoPin, 370);
      delay(100);
      noTone(piezoPin);
      break;
    case 13: 
      Serial.println("3");
      tone(piezoPin, 392);
      delay(100);
      noTone(piezoPin);
      break;
    case 12: 
      Serial.println("4");
      tone(piezoPin, 415);
      delay(100);
      noTone(piezoPin);
      break;
    case 24: 
      Serial.println("5");
      tone(piezoPin, 440);
      delay(100);
      noTone(piezoPin); 
      break;
    case 94: 
      Serial.println("6");
      tone(piezoPin, 466);
      delay(100);
      noTone(piezoPin); 
      break;
    case 8: 
      Serial.println("7");
      tone(piezoPin, 494);
      delay(100);
      noTone(piezoPin); 
      break;
    case 28: 
      Serial.println("8");
      tone(piezoPin, 523);
      delay(100);
      noTone(piezoPin); 
      break;
    case 90: 
      Serial.println("9");
      tone(piezoPin, 554);
      delay(100);
      noTone(piezoPin); 
      break;
    case 82: 
      Serial.println("0");
      tone(piezoPin, 587);
      delay(100);
      noTone(piezoPin); 
      break;

      // # and *
    case 66: 
      Serial.println("*"); 
      break;
    case 74: 
      Serial.println("#"); 
      break;
      
      // otherwise...
    default: 
      Serial.println("Code is :" + c); 
      break;
    }
  }

  // Unfortunately due to technical difficulties, this function is unfinished, and does not provide a consistent Output.
}

void handleReceivedTinyIRData(uint16_t aAddress, uint8_t aCommand, bool isRepeat) { // This function, alike the one above it, also tries to find the code of an IR remote button press and assign it to a command.
  logEvent("Infrared Code received: " + aCommand);                                  // However, because of technical difficulties, I am unsure as to the validity of this segment of the main code, 
  if (aCommand == 70) {                                                             // as there have been a few troubles getting the IR remote to produce an output.
    logEvent("IR Command - Up Pressed - Light Off");
    digitalWrite(ledRed, HIGH);
  }
  if (aCommand == 21) {
    logEvent("IR Command - Down Pressed - Light Off");
    digitalWrite(ledRed, LOW);
  }
  if (aCommand == 68) {
    Serial.println("Left");
  }
  if (aCommand == 67) {
    Serial.println("Right");
  }
}

void piezoBuzzerAlert() {
  /* 
  INITIAL THEME: when the buzzer (piezo) gets a parameter variable of something "dangerous" in the program's game, sound the alert.
  @params none
  @return none

  PROPOSED ADJUSTED THEME: when the Infrared Remote outputs a specific code (ARROWS, NUMBERS, ETC.), play a melody (a group of tone commands, delayed in particular ways to form music).
  @params IR remote code
  @return none
*/

// This tone system which is supposed to be the melody of the Default Dance from Fortnite, showcasing the Piezo's output.
  tone(piezoPin, 349);  // Send sound signal... NOTE F4
  delay(200);
  noTone(piezoPin);
  delay(500);
  tone(piezoPin, 349);  // Send sound signal... NOTE F4
  delay(100);
  noTone(piezoPin);
  delay(100);
  tone(piezoPin, 349);  // Send sound signal... NOTE F4
  delay(100);
  noTone(piezoPin);
  delay(100);
  tone(piezoPin, 392);  // Send sound signal... NOTE G4
  delay(200);
  noTone(piezoPin);
  delay(100);
  tone(piezoPin, 415);  // Send sound signal... NOTE GS4
  delay(300);
  noTone(piezoPin);
  delay(200);
  tone(piezoPin, 349);  // Send sound signal... NOTE F4
  delay(100);
  noTone(piezoPin); //First riff of fortnite dance ends here
  delay(1000);
  tone(piezoPin, 349);  // Send sound signal... NOTE F4
  delay(250);
  noTone(piezoPin);
  delay(300);
  tone(piezoPin, 349);  // Send sound signal... NOTE F4
  delay(100);
  noTone(piezoPin);
  delay(100);
  tone(piezoPin, 392);  // Send sound signal... NOTE G4
  delay(100);
  noTone(piezoPin);
  delay(100);
  tone(piezoPin, 392);  // Send sound signal... NOTE G4
  delay(200);
  noTone(piezoPin);
  delay(100);
  tone(piezoPin, 415);  // Send sound signal... NOTE GS4
  delay(400);
  noTone(piezoPin);
  delay(100);
  tone(piezoPin, 392);  // Send sound signal... NOTE G4
  delay(200);
  noTone(piezoPin);
  delay(100);
  tone(piezoPin, 349);  // Send sound signal... NOTE F4
  delay(200);
  noTone(piezoPin);
  delay(100);
  tone(piezoPin, 311);  // Send sound signal... NOTE DS4
  delay(200);
  noTone(piezoPin);
  delay(100);
  tone(piezoPin, 415);  // Send sound signal... NOTE GS4
  delay(200);
  noTone(piezoPin);
  delay(100);
  tone(piezoPin, 392);  // Send sound signal... NOTE G4
  delay(100);
  noTone(piezoPin);
  delay(100);
  tone(piezoPin, 311);  // Send sound signal... NOTE DS4
  delay(100);
  noTone(piezoPin); // After 1 second, play final riff.
  delay(500);
  tone(piezoPin, 349);  // Send sound signal... NOTE F4
  delay(30);
  noTone(piezoPin);
  delay(100);
  tone(piezoPin, 392);  // Send sound signal... NOTE G4
  delay(250);
  noTone(piezoPin);
  delay(100);
  tone(piezoPin, 392);  // Send sound signal... NOTE G4
  delay(250);
  noTone(piezoPin);
  delay(100);
  tone(piezoPin, 311);  // Send sound signal... NOTE DS4
  delay(250);
  noTone(piezoPin);
  delay(100);
  tone(piezoPin, 349);  // Send sound signal... NOTE F4
  delay(100);
  noTone(piezoPin);
  delay(100);

}

void environmentalAlarmSystem() {
  /* 
  when the distanceSensorEnvironmentalCheck function calls this function (in the instance of a danger to the electronic board's placement), sound the alarm
  @params 'distanceSensorEnvironmentalCheck' output
  @return environmental error alert

  // Unfortunately due to time restraints, this function is unfinished, and does not provide any Output or Input.
*/
}

void distanceSensorEnvironmentalCheck() {
  /* 
  when the the base of the arduino is too close to an obstacle (for instance a desk or a wall), send a parameter to the piezo buzzer to sound the alarm.
  @params none
  @return 'distanceSensorEnvironmentalCheck' output
*/
  digitalWrite(trigPin, LOW);
  //Serial.println("Trig Pin (Sonar) set to LOW");
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  //Serial.println("Trig Pin (Sonar) set to HIGH");
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //Serial.println("Trig Pin (Sonar) set to LOW");
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  int distance = duration * 0.034 / 2;  // Speed of sound wave divided by 2 (go and back)

  // Unfortunately due to resource difficulties, this function is unfinished, and does not provide a consistent Output.
}