#include "subsystems/Shooter.h"

Shooter::Shooter()
{
    Shooter1 = new TalonFX(61);
    Shooter2 = new TalonFX(62);
}
void Shooter::initMotors()
{
    Shooter1->ConfigFactoryDefault();
    Shooter2->ConfigFactoryDefault();
    
    Shooter1->SetInverted(false);
    Shooter2->SetInverted(false);

    Shooter2->Follow(*Shooter1);
}

void Shooter::runShooter(double forward, double reverse,double ESTOP)
{
    
    if (forward == 1)
    {
        speed += .05;
    }
    else if(reverse == 1)
    {
        speed -= 0.05;
    }
    else if(ESTOP == 1)
    {
        speed =0;
    }
    else
    {
        Shooter1->Set(ControlMode::PercentOutput,speed);
        cout<<"Shooter Speed is: "<<speed<<endl;
    }
    
    
   /*if(forward>.1)
    {
        Shooter1->Set(ControlMode::PercentOutput,5);
        //Shooter2->Set(ControlMode::PercentOutput,5);
    }
    else if(reverse>.1)
    {
        Shooter1->Set(ControlMode::PercentOutput,-5);
       // Shooter2->Set(ControlMode::PercentOutput,-5);
    }
    else
    {
        Shooter1->Set(ControlMode::PercentOutput,0);
        //Shooter2->Set(ControlMode::PercentOutput,0);
    }*/
}
void Shooter::coolShot(double distance)
{
    double slopefactor = 0;
    double constant = 0;
    double equation = distance*slopefactor+constant;
    Shooter1->Set(ControlMode::PercentOutput,equation);

}