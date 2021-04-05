#pragma once

#include <ctre/Phoenix.h>
#include <iostream>

using namespace std;
using namespace frc;

class Color
{
 public:
     Color();
     void runColorWheel(double, double);
 private:
     VictorSPX * ColorMotor;   
};