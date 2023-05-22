// SD Card Module
#include <SPI.h>
#include <SD.h>

// Real Time Clock (RTC)
#include "RTClib.h"
RTC_Millis rtc;     // Software Real Time Clock (RTC)
DateTime rightNow;  // used to store the current time.

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
}


void potentiometerVolumeAdjust() {
  /* 
  when the potentiometer's state is changed, the volume of the program on the monitor will increase or decrease accordingly.
  @params none
  @return -
*/
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
}

void infraredRemoteControllerInput() {
  /* 
  when the remote's (connected to the electronic board) presses specific buttons (inputs, ie. button 1,2,3,FUNC/STOP,VOLUME), specific outputs will occur.
  @params none
  @return -
*/
}

void piezoBuzzerAlert() {
  /* 
  when the buzzer (piezo) gets a parameter variable of something "dangerous" in the program's game, sound the alert.
  @params none
  @return -
*/
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
}
