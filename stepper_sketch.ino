#include <Stepper.h>

// Define pin connections & motor's steps per revolution
const int s1dirPin = 19;
const int s1stepPin = 18;
const int s1sleepPin = 15;
//const int s1resetPin = 

const int s2dirPin = 9;
const int s2stepPin = 10;

const int stepsPerRevolution = 200;

void setup()
{
	// Declare pins as Outputs
	pinMode(s1stepPin, OUTPUT);
	pinMode(s1dirPin, OUTPUT);
  pinMode(s1sleepPin, OUTPUT);

  pinMode(s2stepPin, OUTPUT);
  pinMode(s2dirPin, OUTPUT);
}
void loop()
{
  // Set motor direction clockwise
	digitalWrite(s1dirPin, LOW);
  digitalWrite(s1sleepPin, HIGH);
	// Spin motor slowly
	for(int x = 0; x < stepsPerRevolution; x++)
	{
		digitalWrite(s1stepPin, HIGH);
		delayMicroseconds(2000);
		digitalWrite(s1stepPin, LOW);
		delayMicroseconds(2000);
	}
  

  /*digitalWrite(s2dirPin, LOW);
  // Spin motor slowly
	for(int x = 0; x < stepsPerRevolution; x++)
	{
    digitalWrite(s2stepPin, HIGH);
		delayMicroseconds(2000);
    digitalWrite(s2stepPin, LOW);
		delayMicroseconds(2000);
  }*/
	delay(1000); // Wait a second
	
	// Set motor direction counterclockwise
	/*digitalWrite(dirPin, LOW);

	// Spin motor quickly
	for(int x = 0; x < stepsPerRevolution; x++)
	{
		digitalWrite(stepPin, HIGH);
		delayMicroseconds(1000);
		digitalWrite(stepPin, LOW);
		delayMicroseconds(1000);
	}
	delay(1000); // Wait a second*/
}