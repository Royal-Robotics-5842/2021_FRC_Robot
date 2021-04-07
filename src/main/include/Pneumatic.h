#pragma once
#include "frc/Compressor.h"
#include "frc/Solenoid.h"
#include "frc/DoubleSolenoid.h"
#include <iostream>

using namespace frc;

class Pneumatics
{
public:
    Pneumatics();
    void pIntake(bool, bool);
    void pColor(double);
private:
    Compressor * pCompressor;
    //Solenoid* colorWheelSingle;
    frc::Solenoid Intake{0};
    frc::Solenoid colorWheelSingle{7};
   

};

