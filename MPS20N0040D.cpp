/* MPS20N0040D.cpp - MPS20N0040D Pressure Sensor Library
 *
 */

#include "MPS20N0040D.h"
#include "Arduino.h"

MPS20N0040D::MPS20N0040D() {}

/// @brief Attach sensor.
/// @param pin arduino pin connected to the sensor.
void MPS20N0040D::begin(byte pin) {
  _pin = pin;
  pinMode(_pin, INPUT);
}

/// @brief Get sensor pressure.
/// @return Measured pressure (unit: Bar).
float MPS20N0040D::read() {
  return (analogRead(_pin) - OFFSET) * BAR_FACTOR / (FULLSCALE - OFFSET);
}
