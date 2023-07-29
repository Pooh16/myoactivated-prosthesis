#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int servoPin1 = 2; // Pin number for servo 1 little
int servoPin2 = 4; // Pin number for servo 2 ring
int servoPin3 = 16; // Pin number for servo 3 middle
int servoPin4 = 17; // Pin number for servo 4 index
int servoPin5 = 5; // Pin number for servo 5 thumb


int sensorValue = 0;

void setup() {
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  servo5.attach(servoPin5);
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(180);
  servo5.write(180);
  Serial.begin(9600);
}

void loop() {
 
  if (Serial.available() > 0) {
    // read the incoming byte:
    sensorValue = Serial.read();
    Serial.print(sensorValue);

  }
  // Move little servo 1 based on sensor value and threshold
  if (sensorValue == 1) {
    servo1.write(90); // Move to 0 degrees
  } else {
    servo1.write(0); // Move to 90 degrees
  }

  // Move ring servo 2 based on sensor value and threshold
  if (sensorValue == 1) {
    servo2.write(90); // Move to 45 degrees
  } else {
    servo2.write(0); // Move to 90 degrees
  }

  // Move middle servo 3 based on sensor value and threshold
  if (sensorValue == 1) {
    servo3.write(90); // Move to 90 degrees
  } else {
    servo3.write(0); // Move to 135 degrees
  }

  // Move index servo 4 based on sensor value and threshold
  if (sensorValue == 1) {
    servo4.write(90); // Move to 135 degrees
  } else {
    servo4.write(180); // Move to 180 degrees
  }

  // Move servo 5 thumb based on sensor value and threshold
  if (sensorValue == 1) {
    servo5.write(90); // Move to 180 degrees
  } else {
    servo5.write(180); // Move to 90 degrees
  }

  delay(100); // Delay between readings and movements
}
