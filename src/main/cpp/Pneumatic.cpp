#include "pneumatic.h"

int Color = 0;

using namespace std;
using namespace frc;

//Compressor compressor(0);
// Solenoid colorWheelSingle(7);
// Solenoid intake(0);

Pneumatics::Pneumatics()
{
   pCompressor->Start();
}
void Pneumatics::pColor(double ColorControl)
{
    pCompressor->Start();
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
    pCompressor->Start();
    if (ArmOut)
    {
        Intake.Set(true);
        cout<<"Hi";
    }
    if (ArmIn)
    {
        Intake.Set(false);
    }


}


