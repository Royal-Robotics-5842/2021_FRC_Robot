#include"subsystems/Intake.h"

Intake::Intake(){
    IntakeMotor = new VictorSPX(1);
}
void Intake::InitIntake()
{
    
    IntakeMotor->SetInverted(false);
    IntakeMotor->SetNeutralMode(NeutralMode::Brake);
}
void Intake::RunIntake(double forward)//, double reverse)
{
    IntakeMotor->Set(ControlMode::PercentOutput, forward);
    /*if(forward>.1)
    {
        IntakeMotor->Set(ControlMode::PercentOutput,100);
    }
    else if(reverse>.1)
    {
        IntakeMotor->Set(ControlMode::PercentOutput,-100);
    }
    else
    {
        IntakeMotor->Set(ControlMode::PercentOutput,0);
    }*/
    

}