#include <Arduino.h>
#include "imu.h"
#include "pid.h"
#include "motor_control.h"
#include "wifi_control.h"

void initFlightController() {
  Serial.begin(115200);

  initIMU();
  initMotors();
  initWiFi();

  Serial.println("Drone Ready");
}

void flightLoop() {
  readIMU();

  float rollOutput  = computePID(getRoll());
  float pitchOutput = computePID(getPitch());
  float yawOutput   = computePID(getYaw());

  updateMotors(rollOutput, pitchOutput, yawOutput);

  delay(10);
}
