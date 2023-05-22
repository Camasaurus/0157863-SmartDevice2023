// C++ code
//

#define REDLIGHTLED A0


void setup()
{
  pinMode(REDLIGHTLED, OUTPUT);
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(REDLIGHTLED, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  // turn the LED off by making the voltage LOW
  digitalWrite(REDLIGHTLED, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}