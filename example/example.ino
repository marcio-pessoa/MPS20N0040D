#include <MPS20N0040D.h>

MPS20N0040D sensor;

void setup() {
  Serial.begin(9600);
  sensor.attach(0);
}

void loop() {
  Serial.println(String(sensor.read()) + " kPa");
  Serial.println();
  delay(2000);
}
