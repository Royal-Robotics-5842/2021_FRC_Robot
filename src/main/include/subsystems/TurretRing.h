#pragma once

#include <ctre/Phoenix.h>
#include <iostream>
#include "limelight.h"

using namespace std;
using namespace frc;

class Turret
{
 public:
     Turret();
     void runTurret(double,double);
     void autoRotate(bool button);
     int readytoshoot;
 private:
     VictorSPX * TurretMotor;
     
};