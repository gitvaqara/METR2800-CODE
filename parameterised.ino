/**
 * --------- Team Giraffes -----------
 * -----------------------------------
 * -----------------------------------
 * ----------- Main Code -------------
 * -----------------------------------
 * -----------------------------------
 */

// including the necessary libraries
#include <SoftwareSerial.h>
#include <Stepper.h>
#include <Servo.h>
//#include <DFRobot_LIDAR07.h>


// initialising DC MOTOR driver pins
// Back Motor - RIGHT
const int SPEED_RBACK = 1;
const int IN_RBACK = 3;
const int OUT_RBACK = 2;

// Back Motor - LEFT
const int SPEED_LBACK = 6;
const int IN_LBACK = 4;
const int OUT_LBACK = 5;

// Front Motor - LEFT
const int SPEED_LFRONT = 7;
const int IN_LFRONT = 8;
const int OUT_LFRONT = 9;

// Front Motor - RIGHT
const int SPEED_RFRONT = 12;
const int IN_RFRONT = 11;
const int OUT_RFRONT = 10;


// initialising STEPPER driver pins
// Intialising the amount of Steps per Revolution
const int StepsPerRev = 200;

// STEPPER Motor - Left
const int SLdirection = 23;
const int SLstep = 22;
const int SLMS3 = 19;

// STEPPER Motor - RIGHT
const int SRdirection = 24;
const int SRstep = 25;
const int SRMS3 = 28;

// initialising SERVO pins
const int SERVO_MAIN_PIN = 14;
const int SERVO_BLOCK_PIN = 18;

Servo MAIN, BLOCK;

// Initialising TOF IR sensor pins


// initialising IR sensor pins
const int IRSENSOR = 29;

// Creating the AccelStepper Instances
Stepper stepperLEFT(StepsPerRev, SLstep, SLdirection);
Stepper stepperRIGHT(StepsPerRev, SRstep, SRdirection);

void setup() {
  // Changing the Baud Rate for the TOF IR Sensor
  // Serial.begin(115200); // Not using the TOF IR sensor yet
  
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

  // Attaching the servo pins to the Servo Instances
  MAIN.attach(SERVO_MAIN_PIN);
  BLOCK.attach(SERVO_BLOCK_PIN);

  // Stepper Configurations
  // Declare MS3 pins as Outputs
  pinMode(SLMS3, OUTPUT);
  pinMode(SRMS3, OUTPUT);

  // Set MS3 pins to HIGH
  digitalWrite(SLMS3, HIGH);
  digitalWrite(SRMS3, HIGH);

  // Setting up the TOF IR SENSOR
  

  // Setting up the IR SENSOR
  pinMode(IRSENSOR, INPUT_PULLUP);


  /* ----- Code to Pickup a Ball ---------
     -------------------------------------
     ------ Run with the following -------
     Distance from Base to Stepup: 16.5cm
     Scoop lined up with the highest ball
      Scoop rotation position not needed
     -------------------------------------
     -------------------------------------
  */
  move_mainservo_pos30(); // Moves the Servo to the starting position 
  delay(5000); 
  move_mainservo_pos168(); // Moves the Servo to a flat position
  delay(6000); // Can reduce slightly to 5000
  forward_setup();
  go();
  delay(2000);
  stop();
  move_mainservo_pos160(); // Tilts the servo up slightly to pick up the ball
  delay(2500);
  back_setup();
  go();
  delay(7500);
  stop();
  rotate_anticlockwise_setup();
  go();
  delay(10600); // 5300 for 90degree rotation; 10600 for 180degree rotation
  stop();
  delay(1000);
  move_mainservo_pos120();
  delay(5000);
  // 
  back_setup();
  go();
  delay(1000); // Experiment with this to see how far back to go in order to drop ball in


}

void loop() {
  // for(int x = 1; x<=5; x++){
  //   move_servo(30*x);
  //   delayMicroseconds(10000000);
  // }
  // forward_setup();
  // go();
  // speed(200);
  // delay(5000);
  // back_setup();
  // speed(50);

  // If not using TOF IR OR Yellow IR, loop not being used
}

/* -----------------------------------
 * -----------------------------------
 *        Movement Functions
 * -----------------------------------
 * -----------------------------------
 */

void go() {
  // Set motors to move forward at speed 200
  analogWrite(SPEED_LFRONT, 200); // Left Front Motor speed
  analogWrite(SPEED_RFRONT, 200); // Right Front Motor speed
  analogWrite(SPEED_LBACK, 200);  // Left Back Motor speed
  analogWrite(SPEED_RBACK, 200);  // Right Back Motor speed
}

void speed(int sp){
  if (sp <= 256) {
    analogWrite(SPEED_LFRONT, sp); // Left Front Motor speed
    analogWrite(SPEED_RFRONT, sp); // Right Front Motor speed
    analogWrite(SPEED_LBACK, sp);  // Left Back Motor speed
    analogWrite(SPEED_RBACK, sp);
  }

}

void stop() {
  // Stop all motors
  analogWrite(SPEED_LFRONT, 0); // Left Front Motor speed
  analogWrite(SPEED_RFRONT, 0); // Right Front Motor speed
  analogWrite(SPEED_LBACK, 0);  // Left Back Motor speed
  analogWrite(SPEED_RBACK, 0);  // Right Back Motor speed
}

void forward_setup() {
  // Set motors to move forward
  digitalWrite(IN_LFRONT, HIGH);
  digitalWrite(OUT_LFRONT, LOW); // Left Front Motor

  digitalWrite(IN_RFRONT, HIGH);
  digitalWrite(OUT_RFRONT, LOW); // Right Front Motor

  digitalWrite(IN_LBACK, HIGH);
  digitalWrite(OUT_LBACK, LOW);  // Left Back Motor

  digitalWrite(IN_RBACK, HIGH);
  digitalWrite(OUT_RBACK, LOW);  // Right Back Motor
}

void back_setup() {
  // Set motors to move backward
  digitalWrite(IN_LFRONT, LOW);
  digitalWrite(OUT_LFRONT, HIGH); // Left Front Motor

  digitalWrite(IN_RFRONT, LOW);
  digitalWrite(OUT_RFRONT, HIGH); // Right Front Motor

  digitalWrite(IN_LBACK, LOW);
  digitalWrite(OUT_LBACK, HIGH);  // Left Back Motor

  digitalWrite(IN_RBACK, LOW);
  digitalWrite(OUT_RBACK, HIGH);  // Right Back Motor
}

void strafe_left_setup() {
  // Set motors to strafe left
  digitalWrite(IN_LFRONT, LOW);
  digitalWrite(OUT_LFRONT, HIGH); // Left Front Motor - move backward

  digitalWrite(IN_RFRONT, HIGH);
  digitalWrite(OUT_RFRONT, LOW);  // Right Front Motor - move forward

  digitalWrite(IN_LBACK, HIGH);
  digitalWrite(OUT_LBACK, LOW);   // Left Back Motor - move forward
  
  digitalWrite(IN_RBACK, LOW);
  digitalWrite(OUT_RBACK, HIGH);  // Right Back Motor - move backward
}

void strafe_right_setup() {
  // Set motors to strafe right
  digitalWrite(IN_LFRONT, HIGH);
  digitalWrite(OUT_LFRONT, LOW);  // Left Front Motor - move forward
  digitalWrite(IN_RFRONT, LOW);
  digitalWrite(OUT_RFRONT, HIGH); // Right Front Motor - move backward
  digitalWrite(IN_LBACK, LOW);
  digitalWrite(OUT_LBACK, HIGH);  // Left Back Motor - move backward
  digitalWrite(IN_RBACK, HIGH);
  digitalWrite(OUT_RBACK, LOW);   // Right Back Motor - move forward
}

void rotate_clockwise_setup() {
  // Set motors to rotate clockwise
  digitalWrite(IN_LFRONT, HIGH);
  digitalWrite(OUT_LFRONT, LOW); // Left Front Motor - move forward
  digitalWrite(IN_RFRONT, LOW);
  digitalWrite(OUT_RFRONT, HIGH); // Right Front Motor - move backward
  digitalWrite(IN_LBACK, HIGH);
  digitalWrite(OUT_LBACK, LOW);  // Left Back Motor - move forward
  digitalWrite(IN_RBACK, LOW);
  digitalWrite(OUT_RBACK, HIGH); // Right Back Motor - move backward
}

void rotate_anticlockwise_setup() {
  // Set motors to rotate anti-clockwise
  digitalWrite(IN_LFRONT, LOW);
  digitalWrite(OUT_LFRONT, HIGH); // Left Front Motor - move backward

  digitalWrite(IN_RFRONT, HIGH);
  digitalWrite(OUT_RFRONT, LOW);  // Right Front Motor - move forward

  digitalWrite(IN_LBACK, LOW);
  digitalWrite(OUT_LBACK, HIGH);  // Left Back Motor - move backward

  digitalWrite(IN_RBACK, HIGH);
  digitalWrite(OUT_RBACK, LOW);   // Right Back Motor - move forward
}


/* -----------------------------------
 * -----------------------------------
 *       Arm Control Functions
 * -----------------------------------
 * -----------------------------------
 */


void move_servo(int pos){
  if (pos <= 240 && pos >= 25){
    MAIN.write(pos);
    delay(2000);
    if (pos <= 120) {
      MAIN.write(pos + 1);
    } else {
      MAIN.write(pos - 1);
    }
    delay(500);
  }

}

void move_mainservo_pos30() { 
  // Starting Position for the Arm
  MAIN.write(30);
  delay(2000);
  MAIN.write(0);
  delay(500);
  MAIN.write(30);
  delay(2000);
}

void move_mainservo_pos160() {
  // Pickup positon to tilt ball into servo
  MAIN.write(160);
  delay(2500);
  MAIN.write(160);
  delay(2500);
  MAIN.write(160);
  delay(2500);
}

void move_mainservo_pos168() {
  // Position parallel to floor
  MAIN.write(168);
  delay(2000);
  MAIN.write(140);
  delay(2000);
  MAIN.write(168);
  delay(2000);
  MAIN.write(168);
  delay(2000);
}

void move_mainservo_pos120() {
  // Position required to move servo down
  // Nearly in line with the pillars
  MAIN.write(120);
  delay(2500);
  MAIN.write(120);
  delay(2500);
  MAIN.write(120);
  delay(2500);
}

void move_mainservo_drop() {
  // Lowest position that the servo can go to drop the ball down
  MAIN.write(240);
  delay(2000);
  MAIN.write(240);
  delay(2000);
  MAIN.write(240);
  delay(2000);
}

void move_blockservo_open() {
  // Open positon to let balls into tube
  // Havent plugged these into the PCB, need to test this
  BLOCK.write(0);
  delay(500);
}

void move_blockservo_close() {
  // Closed position to stop balls from rolling out
  // Havent plugged these into the PCB, need to experiment positions
  BLOCK.write(90);
  delay(500);
}