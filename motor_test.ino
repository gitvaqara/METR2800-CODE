
// initialising DC MOTOR driver pins
// Front Motor - RIGHT
const int SPEED_RFRONT = 1;
const int IN_RFRONT = 2;
const int OUT_RFRONT = 3;

// Back Motor - RIGHT
const int SPEED_RBACK = 6;
const int IN_RBACK = 4;
const int OUT_RBACK = 5;

// Front Motor - LEFT
const int SPEED_LFRONT = 7;
const int IN_LFRONT = 8;
const int OUT_LFRONT = 9;

// Back Motor - LEFT
const int SPEED_LBACK = 10;
const int IN_LBACK = 11;
const int OUT_LBACK = 12;

void setup() {
 
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

  
  forward_setup();
  go();
  delay(1000);
  stop();
  /*back_setup();
  go();
  delay(1000);
  stop();
  strafe_left_setup();
  go();
  delay(1000);
  stop();
  strafe_right_setup();
  go();
  delay(1000);
  stop();
  rotate_clockwise_setup():
  go();
  delay(1000);
  stop();
  rotate_anticlockwise_setup();
  go();
  delay(1000);
  stop();*/
}

void loop() {
  // put your main code here, to run repeatedly:

}

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