/**
 * --------- Team Giraffes -----------
 * -----------------------------------
 * -----------------------------------
 * ----------- Main Code -------------
 * -----------------------------------
 * -----------------------------------
 */

// including the necessary libraries
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
const int StepsPerRev = 500;

// STEPPER Motor - Left
const int SLdirection = 23;
const int SLstep = 22;
const int SLMS3 = 19;

// STEPPER Motor - RIGHT
const int SRdirection = 33;
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

  /* -------------- Stepper Configurations -------------- */
  // Declare MS3 pins as Outputs
  pinMode(SLMS3, OUTPUT);
  pinMode(SRMS3, OUTPUT);

  // Set MS3 pins to HIGH
  digitalWrite(SLMS3, HIGH);
  digitalWrite(SRMS3, HIGH);

  // Set the Stepper Speeds
  stepperLEFT.setSpeed(200);
  stepperRIGHT.setSpeed(200);
  /* ----------- End of Stepper Configurations --------- */


  // Setting up the TOF IR SENSOR
  

  // Setting up the IR SENSOR
  pinMode(IRSENSOR, INPUT_PULLUP);


  /* ----- Code to Pickup a Ball ---------
     -------------------------------------
     ------ Run with the following -------
      Distance from Base to Stepup: 14cm
     Scoop lined up with the highest ball
      Scoop rotation position not needed
     -------------------------------------
     -------------------------------------
  */
  //delete these, for resetting only
  mainservo_angle(40);
  delay(5000);

  mainfast_angle(177); //get this moving asap, no delay, concurrent
  
  pickup_ball1();
  driveto_ball2();
  pickup_ball2();
  driveto_ball3();
  pickup_ball3();
  dropball_123();
  disturb_ball();

}

void loop() {
  // If not using TOF IR OR Yellow IR, loop not being used
}


/* -----------------------------------
 * -----------------------------------
 *        Pickup Ball Functions
 * -----------------------------------
 * -----------------------------------
 */

void pickup_ball1() {
 /* Servo Setup Parameters:
    Start Position = 20degrees
    Straight Up = 100degrees
    Tilt up to collect Ball = 150degrees
    Angled Position to collect Highest Ball = 152degrees
    Parallel = 160degrees
    Drop Ball = 175degrees
  */
  blockservo_open(); // Open up the Blocking Servo
  //mainfast_angle(20); // Moves the Servo to the starting position
  mainfast_angle(170); // Moves the Servo to the angled position
  delay(1500);
  mainfast_angle(177);
  delay(2000);
  speed(255);
  delay(750);
  stop();
  mainfast_angle(120); // Tilts the servo up slightly to pick up the ball
  delay(500);
  //blockservo_close();

}

void driveto_ball2() {
  // Drives to the 2nd Ball
  speedtime(-255,6500);
  //back_setup();
  //go();
  //delay(6500);
  //stop();
  rotate_anticlockwise_setup(); // Rotates 
  stepper_midheight();
  go();
  delay(11300); // 5650 for 90degree rotation; 11300 for 180degree rotation
  stop();
  strafe_left_setup();
  go();
  delay(400);
  stop();
}

void pickup_ball2() {
  mainfast_angle(170);
  delay(500);
  mainfast_angle(177); // Moves the Servo to the angled position
  delay(1000); 
  forward_setup();
  go();
  delay(1500);
  stop();
  delay(200);
  blockservo_open(); // Open up the Blocking Servo
  mainfast_angle(120); // Tilts the servo up slightly to pick up the ball
  delay(600);
  blockservo_close();
  //delay(200);
}

/* ---------------------------- Code to Drop Ball 1 & 2 ----------------------- */
/*
void dropball_12() {
  back_setup();
  go();
  delay(3000);
  stop();
  rotate_clockwise_setup();
  go();
  delay(5650);
  stop();
  back_setup();
  go();
  delay(2100);
  stop();
  strafe_right_setup();
  go();
  delay(800);
  stop();
  stepper_any(10000, 'd');
  delay(500);
  mainservo_angle(170);
  delay(1000);
  blockservo_open();
  delay(500);
}
*/
/* ---------------------- End of Code to Drop Ball 1 & 2 ---------------------- */

void driveto_ball3() {
  stepper_baseheight();
  strafe_right_setup();
  go();
  delay(5500);
  stop();
  back_setup();
  mainfast_angle(177);
  go();
  delay(1300);
  stop();
}

void pickup_ball3() {
  //delay(1000);
  //forward_setup();
  //go();
  //delay(150);
  //stop();
  //mainservo_angle(165); // Moves the Servo to the angled position
  mainfast_angle(177);
  delay(200); 
  forward_setup();
  go();
  delay(1400);
  stop();
  delay(200);
  mainfast_angle(100); // Tilts the servo up slightly to pick up the ball
  delay(100);
  blockservo_open(); // Open up the Blocking Servo
  delay(200);
  // blockservo_close();
  // delay(200);
}

void dropball_123() {
  back_setup();
  go();
  delay(1500);
  stop();
  strafe_left_setup();
  go();
  delay(5500);
  back_setup();
  go();
  delay(2800);
  stop();
  rotate_clockwise_setup();
  go();
  delay(5650);
  stop();
  back_setup();
  go();
  delay(2300);
  stop();
  strafe_right_setup();
  go();
  delay(50);
  stop();
  mainservo_angle(170);
  delay(500);
  blockservo_open();
}

void disturb_ball() {
  mainservo_angle(152);
  rotate_clockwise_setup();
  go();
  delay(3000);
  stop();
  forward_setup();
  go();
  delay(3000);
  stop();
}

/* -----------------------------------
 * -----------------------------------
 *        Movement Functions
 * -----------------------------------
 * -----------------------------------
 */


void go() {
  // Set motors to move forward at speed 200
  analogWrite(SPEED_LFRONT, 250); // Left Front Motor speed
  analogWrite(SPEED_RFRONT, 250); // Right Front Motor speed
  analogWrite(SPEED_LBACK, 250);  // Left Back Motor speed
  analogWrite(SPEED_RBACK, 250);  // Right Back Motor speed
}

void speedtime(int sp, int time){
  speed(sp);
  delay(time);
  speed(0);
}

void speed(int sp){
  if (sp >= 0){
    forward_setup();
  } else {
    back_setup();
  }

  if (sp <= 256) {
    if (sp < 0) {
      sp=-sp;
    }
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

// void move_servo(int pos){
//   if (pos <= 240 && pos >= 25){
//     MAIN.write(pos);
//     delay(2000);
//     if (pos <= 120) {
//       MAIN.write(pos + 1);
//     } else {
//       MAIN.write(pos - 1);
//     }
//     delay(500);
//   }
// }
void mainfast_angle(int angle){
  MAIN.write(angle);
}

void mainservo_angle(int angle) {
  MAIN.write(angle-10);
  delay(2000);
  MAIN.write(angle);
  delay(2000);
  MAIN.write(angle);
}

/* -----------------------------------
 * -----------------------------------
 *       Arm Height Functions
 * -----------------------------------
 * -----------------------------------
 */


void stepper_baseheight() {
  // Moving the Stepper to the base height
  for (int i = 0; i < 12000; i++){
    stepperRIGHT.step(1);
    stepperLEFT.step(1);
  }
  delay(500);
}

void stepper_midheight() {
  // Moving the Stepper to the Middle Ball height 
  for (int i = 0; i < 6000; i++){
    stepperRIGHT.step(1);
    stepperLEFT.step(1);
  }
  delay(500);
}

void stepper_any(int steps, char direction) {
  // Takes any amount of Steps and runs it
  for (int i = 0; i < steps; i++){
    if (direction == 'd') { // Moves the stepper down
      stepperRIGHT.step(1);
      stepperLEFT.step(1);
    }
    else if (direction == 'u') { // Moves the stepper up
      stepperRIGHT.step(-1);
      stepperLEFT.step(-1);
    }
  }
}


/* -----------------------------------
 * -----------------------------------
 *         Tube Functionality
 * -----------------------------------
 * -----------------------------------
 */


void blockservo_open() {
  // Open positon to let balls into tube
  // Havent plugged these into the PCB, need to test this
  BLOCK.write(80);
}

void blockservo_close() {
  // Closed position to stop balls from rolling out
  // Havent plugged these into the PCB, need to experiment positions
  BLOCK.write(140);
  delay(500);
}







