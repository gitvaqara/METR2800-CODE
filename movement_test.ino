// Motor A Front Left
int SPEED_CONTROL_A = 11;
int IN_A = 22;
int OUT_A = 23;

// Motor B Back Left
int SPEED_CONTROL_B = 10;
int IN_B = 24;
int OUT_B = 25;

// Motor C Back Right
int SPEED_CONTROL_C = 9;
int IN_C = 26;
int OUT_C = 27;

// Motor D Front Right
int SPEED_CONTROL_D = 8;
int IN_D = 28;
int OUT_D = 29;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(SPEED_CONTROL_A, OUTPUT);
  pinMode(SPEED_CONTROL_B, OUTPUT);
  pinMode(SPEED_CONTROL_C, OUTPUT);
  pinMode(SPEED_CONTROL_D, OUTPUT);
  pinMode(IN_A, OUTPUT);
  pinMode(OUT_A, OUTPUT);
  pinMode(IN_B, OUTPUT);
  pinMode(OUT_B, OUTPUT);
  pinMode(IN_C, OUTPUT);
  pinMode(OUT_C, OUTPUT);
  pinMode(IN_D, OUTPUT);
  pinMode(OUT_D, OUTPUT);
}

void loop() {
  // Go forward
  forward_setup();
  go();
}

////////////////////////////////////////////////////////////
//////////////////// MOVEMENT FUNCTIONS ////////////////////
////////////////////////////////////////////////////////////

void go() {
  analogWrite(SPEED_CONTROL_A, 150); // Motor A speed
  analogWrite(SPEED_CONTROL_B, 75); // Motor B speed
  analogWrite(SPEED_CONTROL_C, 75); // Motor C speed
  analogWrite(SPEED_CONTROL_D, 75); // Motor D speed
}

void stop() {
  analogWrite(SPEED_CONTROL_A, 0); // Motor A speed
  analogWrite(SPEED_CONTROL_B, 0); // Motor B speed
  analogWrite(SPEED_CONTROL_C, 0); // Motor C speed
  analogWrite(SPEED_CONTROL_D, 0); // Motor D speed
}

void forward_setup() {
  // A Forward
  digitalWrite(IN_A, HIGH);
  digitalWrite(OUT_A, LOW);
  // B Forward
  digitalWrite(IN_B, HIGH);
  digitalWrite(OUT_B, LOW);
  // C Forward
  digitalWrite(IN_C, HIGH);
  digitalWrite(OUT_C, LOW);
  // D Forward
  digitalWrite(IN_D, HIGH);
  digitalWrite(OUT_D, LOW);
}

void back_setup() {
  // A Backward
  digitalWrite(IN_A, LOW);
  digitalWrite(OUT_A, HIGH);
  // B Backward
  digitalWrite(IN_B, LOW);
  digitalWrite(OUT_B, HIGH);
  // C Backward
  digitalWrite(IN_C, LOW);
  digitalWrite(OUT_C, HIGH);
  // D Backward
  digitalWrite(IN_D, LOW);
  digitalWrite(OUT_D, HIGH);
}

void strafe_left_setup() {
  // A Backward
  digitalWrite(IN_A, LOW);
  digitalWrite(OUT_A, HIGH);
  // B Forward
  digitalWrite(IN_B, HIGH);
  digitalWrite(OUT_B, LOW);
  // C Backward
  digitalWrite(IN_C, LOW);
  digitalWrite(OUT_C, HIGH);
  // D Forward
  digitalWrite(IN_D, HIGH);
  digitalWrite(OUT_D, LOW);
}

void strafe_right_setup() {
  // A Forward
  digitalWrite(IN_A, HIGH);
  digitalWrite(OUT_A, LOW);
  // B Backward
  digitalWrite(IN_B, LOW);
  digitalWrite(OUT_B, HIGH);
  // C Forward
  digitalWrite(IN_C, HIGH);
  digitalWrite(OUT_C, LOW);
  // D Backward
  digitalWrite(IN_D, LOW);
  digitalWrite(OUT_D, HIGH);
}

void rotate_clockwise_setup() {
  // A Forward
  digitalWrite(IN_A, HIGH);
  digitalWrite(OUT_A, LOW);
  // B Forward
  digitalWrite(IN_B, HIGH);
  digitalWrite(OUT_B, LOW);
  // C Backward
  digitalWrite(IN_C, LOW);
  digitalWrite(OUT_C, HIGH);
  // D Backward
  digitalWrite(IN_D, LOW);
  digitalWrite(OUT_D, HIGH);
}

void rotate_anticlockwise_setup() {
  // A Backward
  digitalWrite(IN_A, LOW);
  digitalWrite(OUT_A, HIGH);
  // B Backward
  digitalWrite(IN_B, LOW);
  digitalWrite(OUT_B, HIGH);
  // C Forward
  digitalWrite(IN_C, HIGH);
  digitalWrite(OUT_C, LOW);
  // D Forward
  digitalWrite(IN_D, HIGH);
  digitalWrite(OUT_D, LOW);
}
