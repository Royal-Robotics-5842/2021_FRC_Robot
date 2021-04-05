#include "pneumatic.h"

int Color = 0;

using namespace std;
using namespace frc;

Compressor compressor(0);
Solenoid colorWheelSingle(7);
Solenoid intake(0);

Pneumatics::Pneumatics()
{

}
void Pneumatics::pColor(double ColorControl)
{
    if((ColorControl == 1) && (Color==0))
    {
        colorWheelSingle.Set(true);
        Color=1;
    
    }
    if((ColorControl==1)&& (Color==1))
    {
        colorWheelSingle.Set(false);
        Color=0;
    }
}
void Pneumatics::pIntake(bool ArmOut,bool ArmIn)
{
    if (ArmOut)
    {
        intake.Set(true);
    }
    if (ArmIn)
    {
        intake.Set(false);
    }


}


