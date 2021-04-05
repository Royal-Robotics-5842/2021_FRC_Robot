#pragma once

#include <ctre/Phoenix.h>
#include <iostream>

using namespace std;
using namespace frc;

class Feeder
{
 public:
     Feeder();
     void runFeeder(double,double);
 private:
     VictorSPX * FeederMotor;
};