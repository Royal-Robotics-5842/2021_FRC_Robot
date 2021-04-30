#pragma once

#include <ctre/Phoenix.h>
#include <iostream>

using namespace std;
using namespace frc;

class Shooter
{
 public:
     Shooter();
     void runShooter(double,double,double);
     void initMotors();
     void coolShot(double);
     double speed = 0;
 private:
      TalonFX * Shooter1;
      TalonFX * Shooter2;
      
};