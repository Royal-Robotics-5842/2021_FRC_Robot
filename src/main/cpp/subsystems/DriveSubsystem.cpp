// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"
using namespace DriveConstants;

DriveSubsystem::DriveSubsystem()
 : m_left1{kLeftMotor1Port},
  m_left2{kLeftMotor2Port},
      m_right1{kRightMotor1Port},
      m_right2{kRightMotor2Port},
      m_leftEncoder{kLeftEncoderPorts[0], kLeftEncoderPorts[1]},
      m_rightEncoder{kRightEncoderPorts[0], kRightEncoderPorts[1]},
      m_odometry{m_gyro.GetRotation2d()} {
  // Set the distance per pulse for the encoders
  m_leftEncoder.SetDistancePerPulse(kEncoderDistancePerPulse);
  m_rightEncoder.SetDistancePerPulse(kEncoderDistancePerPulse);
  m_left2.SetInverted(false);
  m_left1.SetInverted(false);
  m_right1.SetInverted(true);
  m_right2.SetInverted(true);

  ResetEncoders();
} 

void DriveSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}
void DriveSubsystem::ResetEncoders() {
  m_leftEncoder.Reset();
  m_rightEncoder.Reset();
}


void DriveSubsystem::TankDriveVolts(double left, double right){
  m_left1.Set(left);
  m_left2.Set(left);
  m_right1.Set(right);
  m_right2.Set(right);  //Made by Teddy
}
