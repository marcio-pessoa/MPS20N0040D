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

/* attach
 *
 * Description
 *   Attach sensor.
 *
 *   sensor.attach(byte pin)
 *
 * Parameters
 *   pin: Arduino pin connected to sensor pin
 *
 * Returns
 *   void
 */
void MPS20N0040D::attach(byte pin) {
  _pin = pin;
  pinMode(_pin, INPUT);
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
  float value, result;

  value = analogRead(_pin);
  result = value * 700 / 970 - 115;

  return result;
}
