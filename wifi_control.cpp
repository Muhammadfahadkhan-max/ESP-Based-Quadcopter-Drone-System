#include <WiFi.h>
#include "wifi_control.h"

const char* ssid = "ESP-DRONE";
const char* password = "12345678";

void initWiFi() {
  WiFi.softAP(ssid, password);
}
