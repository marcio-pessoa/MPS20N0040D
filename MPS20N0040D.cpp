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
MPS20N0040D::MPS20N0040D()
{
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
void MPS20N0040D::begin(byte pin)
{
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
 *   float: pressure (Bar)
 */
float MPS20N0040D::read()
{
  int fullScale = 1024;  // max pressure (span) adjust
  float barFactor = 4; // used to convert eletronic value to Bar
  int offset = 0;
  int sensor_raw = analogRead(_pin);

  return (sensor_raw - offset) * barFactor / (fullScale - offset);
}
