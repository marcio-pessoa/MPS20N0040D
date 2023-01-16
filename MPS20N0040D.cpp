/* MPS20N0040D.cpp - MPS20N0040D Pressure Sensor Library
 *
 */

#include "Arduino.h"
#include "MPS20N0040D.h"

/* MPS20N0040D
 *
 * Description
 *   Pressure Sensor.
 *
 *   MPS20N0040D ()
 *
 * Parameters
 *   none
 *
 * Returns
 *   void
 */
MPS20N0040D::MPS20N0040D() {
}

/* begin
 *
 * Description
 *   Attach sensor.
 *
 *   sensor.begin(byte pin)
 *
 * Parameters
 *   pin: Arduino pin connected to sensor pin
 *
 * Returns
 *   void
 */
void MPS20N0040D::begin(byte pin) {
  _pin = pin;
  _offset = 41;
  pinMode(_pin, INPUT);
}

/* calibrate
 *
 * Description
 *   Calibrate sensor with zero value.
 *
 *   sensor.calibrate()
 *
 * Parameters
 *   none
 */
void MPS20N0040D::calibrate() {
  int offset = 5;
  _offset = _readSensor() + offset;
}

/* read
 *
 * Description
 *   Get sensor pressure.
 *
 *   sensor.read()
 *
 * Parameters
 *   none
 *
 * Returns
 *   float: pressure (kPa)
 */
float MPS20N0040D::read() {
  int fullScale = 963; // max pressure (span) adjust

  return (_readSensor() - _offset) * 700.0 / (fullScale - _offset);
}

/* readSensor
 *
 * Description
 *   Get sensor raw data.
 *
 *   sensor.readSensor()
 *
 * Parameters
 *   none
 *
 * Returns
 *   int: sensor raw data (0 ~ 1024)
 */
int MPS20N0040D::_readSensor() {
  return analogRead(_pin);
}
