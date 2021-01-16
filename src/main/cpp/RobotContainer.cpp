// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "subsystems/DriveSubsystem.h"

using namespace frc;
using namespace std;
RobotContainer::RobotContainer() : m_autonomousCommand(*&m_subsystem) {
  // Initialize all of your commands and subsystems here
  Controller1 = new XboxController(0);
  Controller2 = new XboxController(1);
  
  //m_subsystem = new DriveSubsystem();

  // Configure the button bindings
  ConfigureButtonBindings();
  cout<<"Gamer";
  m_subsystem->SetDefaultCommand(RunCommand(
      [this] {
        m_subsystem->TankDriveVolts(
            Controller1->GetY(frc::GenericHID::kLeftHand),
            Controller2->GetX(frc::GenericHID::kRightHand));
      },
      {&m_Drivesubsystem}));
}

void RobotContainer::ConfigureButtonBindings() {
  
} 

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
