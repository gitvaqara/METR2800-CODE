#include <SoftwareSerial.h>
#include <Servo.h>

Servo MAIN, BLOCK;

void setup() {
  MAIN.attach(14);
  BLOCK.attach (18);
}

void loop() {
  if (Serial.available() > 0) {
      char input = Serial.read();

      static int posmain = MAIN.read();
      static int posblock = BLOCK.read();

      if (input == '1'){
        while (true) {
          input = Serial.read();
          posmain = MAIN.read();
          if (input == 'w') {
            posmain += 3;
            MAIN.write(posmain);
            delay(200);
            Serial.print("Servo position is:");
            Serial.println(posmain);
          }
          if (input == 's' && posmain > 0) {
            posmain -= 3;
            MAIN.write(posmain);
            delay(200);
            Serial.print("Servo position is:");
            Serial.println(posmain);
          }
          if (input == 'q') {
          Serial.println("Quit");
          break;
        }
      }
    }
    if (input == '2'){
        while (true) {
          input = Serial.read();
          posblock = BLOCK.read();
          if (input == 'w') {
            posblock += 3;
            BLOCK.write(posblock);
            delay(200);
            Serial.print("Servo position is:");
            Serial.println(posblock);
          }
          if (input == 's' && posblock > 0) {
            posblock -= 3;
            MAIN.write(posblock);
            delay(200);
            Serial.print("Servo position is:");
            Serial.println(posblock);
          }
          if (input == 'q') {
          Serial.println("Quit");
          break;
        }
      }
    }
  }
}
