#include <Arduino.h>
#include <Servo.h>
#include "config.h"
#include "motor_control.h"

Servo m1, m2, m3, m4;

void initMotors() {
  m1.attach(MOTOR1_PIN);
  m2.attach(MOTOR2_PIN);
  m3.attach(MOTOR3_PIN);
  m4.attach(MOTOR4_PIN);
}

void updateMotors(float roll, float pitch, float yaw) {

  int baseThrottle = 1200;

  m1.writeMicroseconds(baseThrottle + roll + pitch - yaw);
  m2.writeMicroseconds(baseThrottle - roll + pitch + yaw);
  m3.writeMicroseconds(baseThrottle + roll - pitch + yaw);
  m4.writeMicroseconds(baseThrottle - roll - pitch - yaw);
}
