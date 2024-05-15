/**
 *           Team Giraffes
 * -----------------------------------
 * -----------------------------------
 *             Main Code
 * -----------------------------------
 * -----------------------------------
 */

// including the necessary libraries
#include <SoftwareSerial.h>
#include <AccelStepper.h>
#include <Servo.h>
#include <DFRobot_LIDAR07.h>


// initialising DC MOTOR driver pins
// Front Motor - RIGHT
const int SPEED_RFRONT = 3;
const int IN_RFRONT = 1;
const int OUT_RFRONT = 2;

// Back Motor - RIGHT
const int SPEED_RBACK = 6;
const int IN_RBACK = 4;
const int OUT_RBACK = 5;

// Front Motor - LEFT
const int SPEED_LFRONT = 9;
const int IN_LFRONT = 7;
const int OUT_LFRONT = 8;

// Back Motor - LEFT
const int SPEED_LBACK = 12;
const int IN_LBACK = 10;
const int OUT_LBACK = 11;


// initialising STEPPER driver pins
// STEPPER Motor - Left
const int SLdirection = 22;
const int SLstep = 23;

// STEPPER Motor - RIGHT
const int SRdirection = 24;
const int SRstep = 25;

// initialising SERVO pins
const int SERVO_MAIN_PIN = 14;
const int SERVO_BLOCK_PIN = 18;

Servo MAIN, BLOCK;

// Initialising TOF IR sensor pins


// initialising IR sensor pins
const int IRSENSOR = 29;

// Creating the AccelStepper Instances
AccelStepper stepperLEFT(1, SLstep, SLdirection);
AccelStepper stepperRIGHT(1, SRstep, SRdirection);

void setup() {
  // Changing the Baud Rate for the TOF IR Sensor
  Serial.begin(115200);
  
  // Setting up the DC MOTOR configurations
  // Front Motor - LEFT
  pinMode(SPEED_LFRONT, OUTPUT);
  pinMode(IN_LFRONT, OUTPUT);
  pinMode(OUT_LFRONT, OUTPUT);

  // Front Motor - RIGHT
  pinMode(SPEED_RFRONT, OUTPUT);
  pinMode(IN_RFRONT, OUTPUT);
  pinMode(OUT_RFRONT, OUTPUT);

  // Back Motor - LEFT
  pinMode(SPEED_LBACK, OUTPUT);
  pinMode(IN_LBACK, OUTPUT);
  pinMode(OUT_LBACK, OUTPUT);

  // Back Motor - RIGHT
  pinMode(SPEED_RBACK, OUTPUT);
  pinMode(IN_RBACK, OUTPUT);
  pinMode(OUT_RBACK, OUTPUT);

  // Setting up the SERVO configurations
  MAIN.attach(SERVO_MAIN_PIN);
  BLOCK.attach(SERVO_BLOCK_PIN);

  // Setting up the TOF IR SENSOR
  

  // Setting up the IR SENSOR
  pinMode(IRSENSOR, INPUT_PULLUP);

}

void loop() {
  // 
  int L = digitalRead(IRSENSOR);// read the sensor 
    
        if(L == 0){
          // Implement Movement Stopping Function HERE
      }else{
      }
    delay(500);





}

/* -----------------------------------
 * -----------------------------------
 *        Movement Functions
 * -----------------------------------
 * -----------------------------------
 */

void go() {
  analogWrite(SPEED_LFRONT, 200); // Motor A speed
  analogWrite(SPEED_RFRONT, 200); // Motor B speed
  analogWrite(SPEED_LBACK, 200); // Motor C speed
  analogWrite(SPEED_RBACK, 200); // Motor D speed
}

void stop() {
  analogWrite(SPEED_LFRONT, 0); // Motor A speed
  analogWrite(SPEED_RFRONT, 0); // Motor B speed
  analogWrite(SPEED_LBACK, 0); // Motor C speed
  analogWrite(SPEED_RBACK, 0); // Motor D speed
}

void forward_setup() {
  // A Forward
  digitalWrite(IN_LFRONT, HIGH);
  digitalWrite(OUT_LFRONT, LOW);
  // B Forward
  digitalWrite(IN_RFRONT, HIGH);
  digitalWrite(OUT_RFRONT, LOW);
  // C Forward
  digitalWrite(IN_LBACK, HIGH);
  digitalWrite(OUT_LBACK, LOW);
  // D Forward
  digitalWrite(IN_RBACK, HIGH);
  digitalWrite(OUT_RBACK, LOW);
}

void back_setup() {
  // A Backward
  digitalWrite(IN_LFRONT, LOW);
  digitalWrite(OUT_LFRONT, HIGH);
  // B Backward
  digitalWrite(IN_RFRONT, LOW);
  digitalWrite(OUT_RFRONT, HIGH);
  // C Backward
  digitalWrite(IN_LBACK, LOW);
  digitalWrite(OUT_LBACK, HIGH);
  // D Backward
  digitalWrite(IN_RBACK, LOW);
  digitalWrite(OUT_RBACK, HIGH);
}

void strafe_left_setup() {
  // A Backward
  digitalWrite(IN_LFRONT, LOW);
  digitalWrite(OUT_LFRONT, HIGH);
  // B Backward
  digitalWrite(IN_RFRONT, HIGH);
  digitalWrite(OUT_RFRONT, LOW);
  // C Backward
  digitalWrite(IN_LBACK, LOW);
  digitalWrite(OUT_LBACK, HIGH);
  // D Backward
  digitalWrite(IN_RBACK, HIGH);
  digitalWrite(OUT_RBACK, LOW);
}

void strafe_right_setup() {
 // A Backward
  digitalWrite(IN_LFRONT, HIGH);
  digitalWrite(OUT_LFRONT, LOW);
  // B Backward
  digitalWrite(IN_RFRONT, LOW);
  digitalWrite(OUT_RFRONT, HIGH);
  // C Backward
  digitalWrite(IN_LBACK, HIGH);
  digitalWrite(OUT_LBACK, LOW);
  // D Backward
  digitalWrite(IN_RBACK, LOW);
  digitalWrite(OUT_RBACK, HIGH);
}

void rotate_clockwise_setup() {
 // A Backward
  digitalWrite(IN_LFRONT, HIGH);
  digitalWrite(OUT_LFRONT, LOW);
  // B Backward
  digitalWrite(IN_RFRONT, HIGH);
  digitalWrite(OUT_RFRONT, LOW);
  // C Backward
  digitalWrite(IN_LBACK, LOW);
  digitalWrite(OUT_LBACK, HIGH);
  // D Backward
  digitalWrite(IN_RBACK, LOW);
  digitalWrite(OUT_RBACK, HIGH);
}

void rotate_anticlockwise_setup() {
  // A Backward
  digitalWrite(IN_LFRONT, LOW);
  digitalWrite(OUT_LFRONT, HIGH);
  // B Backward
  digitalWrite(IN_RFRONT, LOW);
  digitalWrite(OUT_RFRONT, HIGH);
  // C Backward
  digitalWrite(IN_LBACK, HIGH);
  digitalWrite(OUT_LBACK, LOW);
  // D Backward
  digitalWrite(IN_RBACK, HIGH);
  digitalWrite(OUT_RBACK, LOW);
}

/* -----------------------------------
 * -----------------------------------
 *       Arm Control Functions
 * -----------------------------------
 * -----------------------------------
 */

void move_servo_0() {


};



