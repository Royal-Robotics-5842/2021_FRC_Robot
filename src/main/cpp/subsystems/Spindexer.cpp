#include "subsystems/Spindexer.h"

Spindexer::Spindexer(){
    SpindexerMotor = new VictorSPX(8);
}
void Spindexer::initSpindexer(){
    SpindexerMotor->SetInverted(false);
}
void Spindexer::runSpindexer(double forward)//, double reverse)
{
    SpindexerMotor->Set(ControlMode::PercentOutput, forward);
    /*
    if(forward>.1)
    {
        SpindexerMotor->Set(ControlMode::PercentOutput,100);
    }
    else if(reverse>.1)
    {
        SpindexerMotor->Set(ControlMode::PercentOutput,-100);
    }
    else
    {
        SpindexerMotor->Set(ControlMode::PercentOutput,0);
    }*/
    

}
