#include <SPI.h> // SD Card Module
#include <SD.h>
#include "RTClib.h" // Real Time Clock (RTC)
#include <IRremote.h> // Infrared Remote
#include <L298N.h> // Motor Controller
#include <Servo.h> // Servo Motor

// Outputs
#define ledRed A0 // Red LED, connected to pin A0
#define ledYellow A1 // Yellow LED, connected to pin A1
#define ledGreen A2 // Green LED, connected to pin A2
#define piezoPin 8 // Piezo Buzzer Pin

// Inputs
#define echoPin 6 //attach pin D2 Arduino to pin Echo of (Sonar) HC-SR04
#define trigPin A4 //attach pin D3 Arduino to pin Trig of (Sonar) HC-SR04
#define crashSensor 7 // Crash Sensor (button), HIGH or LOW values.
#define lineSensorPin 3 // Line Sensor (light), HIGH or LOW values.
#define IR_INPUT_PIN 2 // IR Remote
#define pot A3 // Potentiometer

// Real Time Clock (RTC)
RTC_Millis rtc;     // Software Real Time Clock (RTC)
DateTime rightNow;  // used to store the current time.

// IR Remote
IRrecv irrecv(IR_INPUT_PIN);
decode_results results;

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
#define SDpin 53

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

  // IR remote
  irrecv.enableIRIn();

  // Traffic Lights
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);

  // DC Motor & Motor Module - L298N
  motor.setSpeed(70);

  // Servo Motor
  myservo.attach(9); //attaches the servo on pin 9 to the servo object.

  //Potentiometer
  pinMode(pot, INPUT);

  //Piezo
  pinMode(piezoPin, OUTPUT);

  //Sonar - HC-SR04
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output.
  pinMode(echoPin, OUTPUT); // Sets the echoPin as an Output.

  //Line Sensor
  pinMode(lineSensorPin, OUTPUT);

  //Crash Sensor
  pinMode(crashSensor, INPUT);
  
  // Real Time Clock (RTC)
  rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
  Serial.println("initialization done.");
  logEvent("System Initialisation...");
}

void loop() {
  // put your main code here, to run repeatedly:
  lineSensorDebugMode();  // as an example.
  servoMotorMonitorSpeed();
  ingameProgressionThroughDCMotorMovement();
  potentiometerVolumeAdjust();
  trafficLightVisualDangerSystem();
  userInterfaceButton();
  infraredRemoteControllerInput();
  piezoBuzzerAlert();
  environmentalAlarmSystem();
  distanceSensorEnvironmentalCheck();  //Is it possible to put in all of the functions in the loop?

  delay(250);
}

void lineSensorDebugMode() {
  /* 
  when the line sensor interacts with a pattern of lines, the sensor will determine if the user can access debug properties of the program.
  @params none
  @return -
*/
  int lineSensorValue = digitalRead(lineSensorPin);
}

void servoMotorMonitorSpeed() {
  /* 
  when the servo motor's state is changed, the speed of the program on the monitor will increase or decrease accordingly.
  @params none
  @return -
*/
}

void ingameProgressionThroughDCMotorMovement() {
  /* 
  over time when the game is playing, the DC motor will move as a visual aid for the player on their progress. dependent on the elapsed time in the game, the difficulty may increase or "dangers" may appear.
  @params none
  @return -
*/
  motor.forward();
  delay(1000);
  motor.stop();
  delay(1000);
  motor.backward();
  delay(1000);
}


void potentiometerVolumeAdjust() {
  /* 
  when the potentiometer's state is changed, the volume of the program on the monitor will increase or decrease accordingly.
  @params none
  @return -
*/
  int potValue = analogRead(pot);
  Serial.println(potValue);
  delay(1000);
}

void trafficLightVisualDangerSystem() {
  /* 
  when the program receives "danger" variables from ingame "danger", the colour of the corresponding LED will turn on (red = high danger, yellow = medium danger, green = low danger)
  @params -
  @return none
*/
}

void userInterfaceButton() {
  /* 
  when the 'crash sensor' button is pressed, the user interface will progress to other options (and while in-game, will enable the pause menu/options)
  @params none
  @return -
*/
  int crashSensorValue = digitalRead(crashSensor);
  if (crashSensorValue == HIGH) {
    Serial.println(crashSensorValue);
    logEvent("Button Activated");
  
    delay(1000);
    logEvent("Button Deactivated");
  }
}

void infraredRemoteControllerInput() {
  /* 
  when the remote's (connected to the electronic board) presses specific buttons (inputs, ie. button 1,2,3,FUNC/STOP,VOLUME), specific outputs will occur.
  @params none
  @return -
*/
  if (irrecv.decode(&results)) {

    int code = results.value;
    if (code == 25245) { // <-- code for Up
      Serial.println("Up");
    }
    if (code == 26775) {
      Serial.println("One");
      digitalWrite(ledRed, HIGH);
    }
    if (code == -26521) {
      Serial.println("Two");
      digitalWrite(ledYellow, HIGH);
    }
    if (code == -20401) {
      Serial.println("Three");
      digitalWrite(ledGreen, HIGH); // To test that the IR Remote works, I have set three LED scenarios, where if the user presses 1 through 3, it will activate the corresponding LEDs.
    } else {
      Serial.println(code);
    }
    irrecv.resume();
  }
}

void piezoBuzzerAlert() {
  /* 
  when the buzzer (piezo) gets a parameter variable of something "dangerous" in the program's game, sound the alert.
  @params none
  @return -
*/
  tone(piezoPin, 5000); // Send 1KHz sound signal...
  delay(100);
  noTone(piezoPin);
}

void environmentalAlarmSystem() {
  /* 
  when the distanceSensorEnvironmentalCheck function calls this function (in the instance of a danger to the electronic board's placement), sound the alarm
  @params 'distanceSensorEnvironmentalCheck' output
  @return -
*/
}

void distanceSensorEnvironmentalCheck() {
  /* 
  when the the base of the arduino is too close to an obstacle (for instance a desk or a wall), send a parameter to the piezo buzzer to sound the alarm.
  @params none
  @return -
*/
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  int distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
}
