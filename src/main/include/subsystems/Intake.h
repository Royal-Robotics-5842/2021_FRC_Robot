#pragma once
#include <ctre/Phoenix.h>
#include <iostream>

using namespace std;
using namespace frc;

class Intake
{
private:
    /* data */
    VictorSPX * IntakeMotor;

    
public:
    Intake(/* args */);
    void InitIntake();
    void RunIntake(double);//,double);
    
};

