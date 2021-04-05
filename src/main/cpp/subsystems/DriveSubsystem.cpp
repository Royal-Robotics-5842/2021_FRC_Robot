// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"
using namespace DriveConstants;
using namespace std;
using namespace frc;

DriveSubsystem::DriveSubsystem():
  m_left1{kLeftMotor1Port},
  m_left2{kLeftMotor2Port},
  m_right1{kRightMotor1Port},
  m_right2{kRightMotor2Port}, ahrs{frc::SPI::Port::kMXP},
  //m_leftEncoder{kLeftEncoderPorts[11], kLeftEncoderPorts[12]},
 // m_rightEncoder{kRightEncoderPorts[13], kRightEncoderPorts[14]},
  m_odometry{ahrs.GetRotation2d()} {
  // Set the distance per pulse for the encoders
  //m_leftEncoder.SetDistancePerPulse(kEncoderDistancePerPulse);
 // m_rightEncoder.SetDistancePerPulse(kEncoderDistancePerPulse);
  m_left2.SetInverted(false);
  m_left1.SetInverted(false);
  m_right1.SetInverted(true);
  m_right2.SetInverted(true);
  m_left1.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor,0,30);
  m_left2.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor,0,30);
  m_right1.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor,0,30);
  m_right2.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor,0,30);
  m_left1.SetSensorPhase(true);
  m_left2.SetSensorPhase(true);
  m_right1.SetSensorPhase(true);
  m_right2.SetSensorPhase(true);

  //PID Controller
  m_left1.Config_kF(0, 0.048927863, 30);
  m_left1.Config_kP(0, DriveConstants::kPDriveVel, 30);
  m_left1.ConfigMotionAcceleration(1*38400/(.1524*wpi::math::pi)/10);
  m_left1.ConfigMotionCruiseVelocity(.5*38400/(.1524*wpi::math::pi)/10);
  
  m_left2.Config_kF(0, 0.048927863, 30);
  m_left2.Config_kP(0, DriveConstants::kPDriveVel, 30);
  m_left2.ConfigMotionAcceleration(1*38400/(.1524*wpi::math::pi)/10);
  m_left2.ConfigMotionCruiseVelocity(.5*38400/(.1524*wpi::math::pi)/10);

  m_right1.Config_kF(0, 0.048927863, 30);
  m_right1.Config_kP(0, DriveConstants::kPDriveVel, 30);
  m_right1.ConfigMotionAcceleration(1*38400/(.1524*wpi::math::pi)/10);
  m_right1.ConfigMotionCruiseVelocity(.5*38400/(.1524*wpi::math::pi)/10);

  m_right2.Config_kF(0, 0.048927863, 30);
  m_right2.Config_kP(0, DriveConstants::kPDriveVel, 30);
  m_right2.ConfigMotionAcceleration(1*38400/(.1524*wpi::math::pi)/10);
  m_right2.ConfigMotionCruiseVelocity(.5*38400/(.1524*wpi::math::pi)/10);
  //ahrs = new AHRS(SPI::Port::kMXP);

  ResetEncoders();
} 

void DriveSubsystem::Periodic() {
  m_odometry.Update(ahrs.GetRotation2d(),
                    units::meter_t(DriveSubsystem::GetLeftEncoder()),
                    units::meter_t(DriveSubsystem::GetRightEncoder()));
  // Implementation of subsystem periodic method goes here.
}
void DriveSubsystem::ResetEncoders() {
  m_left1.SetSelectedSensorPosition(0,0,30);
  m_right1.SetSelectedSensorPosition(0,0,30);
}
void DriveSubsystem::TankDrive(double left, double right){
  m_left1.Set(left);
  m_left2.Set(left);
  m_right1.Set(right);
  m_right2.Set(right); 
}

void DriveSubsystem::TankDriveVolts(units::volt_t left, units::volt_t right){
  /*m_left1.Set(left);
  m_left2.Set(left);
  m_right1.Set(right);
  m_right2.Set(right);  //Made by Teddy*/
  m_leftMotors.SetVoltage(-left);
  cout<<m_left1.GetMotorOutputVoltage();
  m_rightMotors.SetVoltage(-right);
  cout<<m_right1.GetMotorOutputVoltage();
  m_drive.Feed();
  cout<<"Hello World";
}
double DriveSubsystem::GetAverageEncoderDistance() {
  return ((DriveSubsystem::GetLeftEncoder() + DriveSubsystem::GetRightEncoder()/*m_left1.GetSelectedSensorPosition() + m_right1.GetSelectedSensorPosition())*/)/2);
}

double DriveSubsystem::GetLeftEncoder() {
  return m_left1.GetSelectedSensorPosition()*((0.1524 * wpi::math::pi)/(2048*18.75));
}

double DriveSubsystem::GetRightEncoder() {
  return m_right1.GetSelectedSensorPosition()*((0.1524 * (wpi::math::pi))/(2048*18.75));
}

void DriveSubsystem::SetMaxOutput(double maxOutput) {
  m_drive.SetMaxOutput(maxOutput);
}

units::degree_t DriveSubsystem::GetHeading() const {
  return ahrs.GetRotation2d().Degrees();
}

double DriveSubsystem::GetTurnRate() {
  return ahrs.GetRate();
}

frc::Pose2d DriveSubsystem::GetPose() {
  return m_odometry.GetPose();
}

frc::DifferentialDriveWheelSpeeds DriveSubsystem::GetWheelSpeeds() {
  return {units::meters_per_second_t(m_left1.GetSelectedSensorVelocity()*((10*0.1524 * wpi::math::pi)/(2048*18.75))),
          units::meters_per_second_t(m_left1.GetSelectedSensorVelocity()*((10*0.1524 * wpi::math::pi)/(2048*18.75)))};
}

void DriveSubsystem::ResetOdometry(frc::Pose2d pose) {
  ResetEncoders();
  m_odometry.ResetPosition(pose, ahrs.GetRotation2d());
} 
void DriveSubsystem::DriveTest()
{
  m_left1.Set(ControlMode::Velocity,0);
  m_left2.Set(ControlMode::Velocity,0);
  m_right1.Set(ControlMode::Velocity,0);
  m_right2.Set(ControlMode::Velocity,0); 
}