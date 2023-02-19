/* MPS20N0040D.h - MPS20N0040D Pressure Sensor Library
 *
 * Author: Márcio Pessoa <marcio.pessoa@gmail.com>
 * Contributors: none
 *
 * Change log
 * 2023-01-14
 *   Experimental version.
 */

#ifndef MPS20N0040D_h
#define MPS20N0040D_h

#include "Arduino.h"

#define FULLSCALE 1024  // max A/D value (span) adjust
#define BAR_FACTOR 4    // convert eletronic value to pressure unit
#define OFFSET 0

/// @brief MPS20N0040D Pressure Sensor Library
class MPS20N0040D {
 public:
  MPS20N0040D();
  void begin(byte pin);
  float read();

 private:
  byte _pin;
};

#endif
