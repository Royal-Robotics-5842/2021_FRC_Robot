#include "subsystems/ColorWheel.h"
Color::Color()
{
    ColorMotor = new VictorSPX(7);
}
void Color::runColorWheel(double forward, double reverse)
{
    if(forward>.1)
    {
        ColorMotor->Set(ControlMode::PercentOutput,100);
    }
    else if(reverse>.1)
    {
        ColorMotor->Set(ControlMode::PercentOutput,-100);
    }
    else
    {
        ColorMotor->Set(ControlMode::PercentOutput,0);
    }
}