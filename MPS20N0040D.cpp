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

/// @brief Read sensor, raw mode
/// @return int (0 ~ 1024)
int MPS20N0040D::_raw() { return analogRead(_pin); }

/// @brief Span ajust
/// @return float
float MPS20N0040D::_span() {
  int fullScale = 1024;  // max A/D value (span) adjust
  float barFactor = 4;   // convert eletronic value to pressure unit
  return _raw() * barFactor / fullScale;
}

/// @brief Get sensor pressure.
/// @return Measured pressure (unit: Bar).
float MPS20N0040D::read() { return _span() * 0.71; }
