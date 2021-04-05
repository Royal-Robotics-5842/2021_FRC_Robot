#pragma once

#include <ctre/Phoenix.h>
#include <iostream>

using namespace std;
using namespace frc;

class Spindexer
{
 public:
     Spindexer();
     void initSpindexer();
     void runSpindexer(double,double);

 private:
 VictorSPX * SpindexerMotor;




};