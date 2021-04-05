#include "subsystems/TurretRing.h"
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include <iostream>
using namespace std;
#define rotatePort 5
#define tracking 1
#define drive 2

float Kp = -0.1f;
float min_command = 0.05f;

Turret::Turret()
{
    TurretMotor = new VictorSPX(5);
    readytoshoot = 0;
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
void Turret::autoRotate(bool button)
{
    if(button == 1)
    {
        nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("pipeline",tracking);
        if(nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tv",0.0) == 1)
        {
            float heading_error = -(nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tx",0.0));
            float steering_adjust = 0.0f;
            if(nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tx",0.0) > 1)  //aka the robot is to the left of the target
            {
                steering_adjust = Kp*heading_error - min_command;
                cout<<"Should Turn Right"<<endl<<"Motor Output: "<<steering_adjust<<endl;
                TurretMotor->Set(ControlMode::PercentOutput,steering_adjust);
            }   
            else if (nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tx",0.0) < 1)
            {
                steering_adjust = Kp*heading_error + min_command;
                TurretMotor->Set(ControlMode::PercentOutput,steering_adjust);
                cout<<"Should Turn Left"<<endl<<"Motor Output: "<<steering_adjust<<endl;
            }
            else
            {
                cout<<"Ready to Shoot :)"<<endl;
                //return true;
                readytoshoot = 1;
            }
                               
        }
        else
        {
            cout<<"No Target Fount :("<<endl;
            //return false;
            readytoshoot = 0;
        }
        
    }
    else
    {
        nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("pipeline",drive);
    }
}