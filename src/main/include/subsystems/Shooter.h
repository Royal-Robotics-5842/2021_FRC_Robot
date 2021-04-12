#pragma once

#include <ctre/Phoenix.h>
#include <iostream>

using namespace std;
using namespace frc;

class Shooter
{
 public:
     Shooter();
     void runShooter(double,double);
     void initMotors();
     void coolShot(double);
 private:
      TalonFX * Shooter1;
      TalonFX * Shooter2;
};