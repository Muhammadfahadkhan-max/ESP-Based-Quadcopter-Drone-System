#include <Wire.h>
#include "imu.h"

float roll, pitch, yaw;

void initIMU() {
  Wire.begin(21, 22);
}

void readIMU() {
  // simplified simulation (replace with MPU6050 library)
  roll  = random(-10, 10);
  pitch = random(-10, 10);
  yaw   = random(-10, 10);
}

float getRoll()  { return roll; }
float getPitch() { return pitch; }
float getYaw()   { return yaw; }
