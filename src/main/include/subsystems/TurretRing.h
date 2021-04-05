#pragma once

#include <ctre/Phoenix.h>
#include <iostream>

using namespace std;
using namespace frc;

class Turret
{
 public:
     Turret();
     void runTurret(double,double);
     void autoturret();
 private:
     VictorSPX * TurretMotor;
     
};