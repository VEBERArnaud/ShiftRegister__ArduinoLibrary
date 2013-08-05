/*
 ShiftRegister.h - Library for ShiftRegister [74CH595].
 Created by Arnaud VEBER, August 4, 2013.
 http://github.com/VEBERArnaud/ShiftRegister__ArduinoLibrary
 */

#include "Arduino.h"
#include "ShiftRegister.h"


ShiftRegister::ShiftRegister(int SERPin, int RCLKPin, int SRCLKPin, int nbRegPin)
{
    // SER Pin
    pinMode(SERPin, OUTPUT);
    _SERPin = SERPin;
    
    // RCLK Pin
    pinMode(RCLKPin, OUTPUT);
    _RCLKPin = RCLKPin;
    
    // SRCLK Pin
    pinMode(SRCLKPin, OUTPUT);
    _SRCLKPin = SRCLKPin;
    
    // total number of pins out of ShiftRegisters
    _nbRegPin = nbRegPin;
}

void ShiftRegister::write(int configuration[])
{
    digitalWrite(_RCLKPin, LOW);
    for(int i=0; i<_nbRegPin; i++) {
        digitalWrite(_SRCLKPin, LOW);
        digitalWrite(_SERPin, configuration[i]);
        digitalWrite(_SRCLKPin, HIGH);
    }
    digitalWrite(_RCLKPin, HIGH);
}

void ShiftRegister::clear()
{
    int configuration[_nbRegPin];
    for(int i=0; i<_nbRegPin; i++)
        configuration[i] = LOW;
    write(configuration);
}
