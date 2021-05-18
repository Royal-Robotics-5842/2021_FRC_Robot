#include "pneumatic.h"
int Color = 1;


using namespace std;
using namespace frc;


//Compressor compressor(0);


Pneumatics::Pneumatics()
{
  // pCompressor->Start();
colorWheelSingle = new Solenoid(0);
 Intake = new Solenoid(7);

}
void Pneumatics::pColor(double ColorControl1,double ColorControl2)
{
   // cout<<"Button Status: "<<ColorControl1<<"Toggle Status: "<<Color<<endl;
   // pCompressor->Start();
    if((ColorControl1 == 1))// && (Color=1))
    {
        colorWheelSingle->Set(true);
        Color=0;
    
    }
    else if((ColorControl2==1))//&& (Color=0))
    {
        colorWheelSingle->Set(false);
        Color=1;
    }
    else
    {

    }
}
void Pneumatics::pIntake(bool ArmOut,bool ArmIn)
{
   // pCompressor->Start();
    if (ArmOut)
    {
        Intake->Set(true);
        cout<<"Hi";
    }
    if (ArmIn)
    {
        Intake->Set(false);
    }


}


