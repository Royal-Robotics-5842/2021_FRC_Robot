#include "subsystems/Shooter.h"

Shooter::Shooter()
{
    Shooter1 = new TalonFX(61);
    Shooter2 = new TalonFX(62);
}
void Shooter::runShooter(double forward, double reverse)
{
   if(forward>.1)
    {
        Shooter1->Set(ControlMode::PercentOutput,65);
        Shooter2->Set(ControlMode::PercentOutput,65);
    }
    else if(reverse>.1)
    {
        Shooter1->Set(ControlMode::PercentOutput,-65);
        Shooter2->Set(ControlMode::PercentOutput,-65);
    }
    else
    {
        Shooter1->Set(ControlMode::PercentOutput,0);
        Shooter2->Set(ControlMode::PercentOutput,0);
    }
}