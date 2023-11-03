#include "CODBOTS_UltraSonicScan.h"

//ultrasonic
#define ULTRA_TRIG 23
#define ULTRA_ECHO 22

CODBOTS_UltraSonicScan usensor(ULTRA_TRIG,ULTRA_ECHO);
void setup() {
  Serial.begin(115200);
  usensor.begin();
}

void loop() {
  Serial.println(usensor.readSensor());
  delay(10);
}
