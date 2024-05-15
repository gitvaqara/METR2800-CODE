

int front_motor_left1 = 5;
int front_motor_left2 = 4;
int front_motor_right1 = 3;
int front_motor_right2 = 2;


int back_motor_left1 = 8;
int back_motor_left2 = 9;
int back_motor_right1 = 10;
int back_motor_right2 = 11;

void setup() {
  // Initializing front motors pins
  pinMode(front_motor_left1, OUTPUT);
  pinMode(front_motor_left2, OUTPUT);
  pinMode(front_motor_right1, OUTPUT);
  pinMode(front_motor_right2, OUTPUT);

  pinMode(6, OUTPUT); 
  pinMode(1, OUTPUT);

  // Initializing back motor pins
  pinMode(back_motor_left1, OUTPUT);
  pinMode(back_motor_left2, OUTPUT);
  pinMode(back_motor_right1, OUTPUT);
  pinMode(back_motor_right2, OUTPUT);

  pinMode(7, OUTPUT); 
  pinMode(12, OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:   

  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(6, 250); //ENA pin
  analogWrite(1, 250); //ENB pin
  analogWrite(7, 250); //ENA pin
  analogWrite(12, 250); //ENB pin

  //Controlling the spin direction of the FRONT motors:
  digitalWrite(front_motor_left1, LOW);
  digitalWrite(front_motor_left2, HIGH);

  digitalWrite(front_motor_right1, HIGH);
  digitalWrite(front_motor_right2, LOW);

  //Controlling spin direction of the BACK motors:
  digitalWrite(back_motor_left1, HIGH);
  digitalWrite(back_motor_left2, LOW);

  digitalWrite(back_motor_right1, HIGH);
  digitalWrite(back_motor_right2, LOW);
}