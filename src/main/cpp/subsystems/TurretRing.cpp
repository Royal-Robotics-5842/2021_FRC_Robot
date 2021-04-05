#include "subsystems/TurretRing.h"

Turret::Turret()
{
    TurretMotor = new VictorSPX(5);
}
void Turret::runTurret(double forward, double reverse)
{
    if(forward>.1)
    {
        TurretMotor->Set(ControlMode::PercentOutput,100);
    }
    else if(reverse>.1)
    {
        TurretMotor->Set(ControlMode::PercentOutput,-100);
    }
    else
    {
        TurretMotor->Set(ControlMode::PercentOutput,0);
    }
}