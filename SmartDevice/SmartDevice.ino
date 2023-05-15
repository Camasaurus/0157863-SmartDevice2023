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
}

void loop() {
  // put your main code here, to run repeatedly:
  lineSensorDebugMode(); // as an example.

  delay(250);
}

void lineSensorDebugMode() {
/* 
  when the line sensor interacts with a pattern of lines, the sensor will determine if the user can access debug properties of the program.
  @params none
  @return none
*/
}

void piezoBuzzerAlert() {
/* 
  when the buzzer (piezo) gets a parameter variable of something 'dangerous' in the program's game, sound the alert.
  @params -
  @return none
*/
}

void distanceSensorEnvironmentalCheck() {
/* 
  when the the base of the arduino is too close to an obstacle (for instance a desk or a wall), send a parameter to the piezo buzzer to sound the alarm.
  @params none
  @return -
*/
}