/* MPS20N0040D.cpp - MPS20N0040D Pressure Sensor Library
 *
 */

#include "MPS20N0040D.h"
#include "Arduino.h"

MPS20N0040D::MPS20N0040D(byte pin) { begin(pin); }

/// @brief Attach sensor.
/// @param pin arduino pin connected to the sensor.
void MPS20N0040D::begin(byte pin) {
  _pin = pin;
  pinMode(_pin, INPUT);
}

/// @brief Get sensor pressure.
/// @return Measured pressure (unit: Bar).
float MPS20N0040D::read() {
  int fullScale = 1024;  // max A/D value (span) adjust
  float barFactor = 4;   // convert eletronic value to pressure unit
  int offset = 0;
  int sensor_raw = analogRead(_pin);

  return (sensor_raw - offset) * barFactor / (fullScale - offset);
}
