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
  m_right2{kRightMotor2Port},
  m_leftEncoder{kLeftEncoderPorts[11], kLeftEncoderPorts[12]},
  m_rightEncoder{kRightEncoderPorts[13], kRightEncoderPorts[14]},
  m_odometry{ahrs->GetRotation2d()} {
  // Set the distance per pulse for the encoders
  m_leftEncoder.SetDistancePerPulse(kEncoderDistancePerPulse);
  m_rightEncoder.SetDistancePerPulse(kEncoderDistancePerPulse);
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
  ahrs = new AHRS(SPI::Port::kMXP);

  ResetEncoders();
} 

void DriveSubsystem::Periodic() {
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
  m_leftMotors.SetVoltage(left);
  m_rightMotors.SetVoltage(right);
  m_drive.Feed();
}
double DriveSubsystem::GetAverageEncoderDistance() {
  return (m_left1.GetSelectedSensorPosition() + m_right1.GetSelectedSensorPosition())/2;
}

double DriveSubsystem::GetLeftEncoder() {
  return m_left1.GetSelectedSensorPosition();
}

double DriveSubsystem::GetRightEncoder() {
  return m_right1.GetSelectedSensorPosition();
}

void DriveSubsystem::SetMaxOutput(double maxOutput) {
  m_drive.SetMaxOutput(maxOutput);
}

units::degree_t DriveSubsystem::GetHeading() const {
  return ahrs->GetRotation2d().Degrees();
}

double DriveSubsystem::GetTurnRate() {
  return -ahrs->GetRate();
}

frc::Pose2d DriveSubsystem::GetPose() {
  return m_odometry.GetPose();
}

frc::DifferentialDriveWheelSpeeds DriveSubsystem::GetWheelSpeeds() {
  return {units::meters_per_second_t(m_leftEncoder.GetRate()),
          units::meters_per_second_t(m_rightEncoder.GetRate())};
}

void DriveSubsystem::ResetOdometry(frc::Pose2d pose) {
  ResetEncoders();
  m_odometry.ResetPosition(pose, ahrs->GetRotation2d());
} 