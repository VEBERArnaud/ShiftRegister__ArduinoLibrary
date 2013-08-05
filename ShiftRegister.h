/*
 ShiftRegister.h - Library for ShiftRegister [74CH595].
 Created by Arnaud VEBER, August 4, 2013.
 http://github.com/VEBERArnaud
 */

#ifndef ShiftRegister_h
#define ShiftRegister_h

#include "Arduino.h"

class ShiftRegister
{
  public:
    ShiftRegister(int SERPin, int RCLKPin, int SRCLKPin, int nbRegPin);
    void write(int configuration[]);
    void clear();
  private:
    int _nbRegPin;
    int _SERPin;
    int _RCLKPin;
    int _SRCLKPin;
};

#endif
