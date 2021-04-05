#include "subsystems/Feeder.h"

Feeder::Feeder()
{
    FeederMotor = new VictorSPX(3);
}
void Feeder::runFeeder(double forward, double reverse)
{
     if(forward>.1)
    {
        FeederMotor->Set(ControlMode::PercentOutput,100);
    }
    else if(reverse>.1)
    {
        FeederMotor->Set(ControlMode::PercentOutput,-100);
    }
    else
    {
        FeederMotor->Set(ControlMode::PercentOutput,0);
    }
}