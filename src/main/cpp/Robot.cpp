// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
//Progamers are cool
#include "Subsystems/DriveSubsystem.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>
#include "subsystems/ColorWheel.h"
#include "ControllerClass.h"
#include "subsystems/Feeder.h"
#include "subsystems/TurretRing.h"
#include "subsystems/Shooter.h"
#include "subsystems/Intake.h"
#include "subsystems/Spindexer.h"
#include "RobotContainer.h"
#include "Pneumatic.h"
Color * ColorClass;
Feeder * FeederClass;
Turret * TurretClass;
Shooter * ShooterClass;
Spindexer * spindexerClass;
Intake * IntakeClass;
Pneumatics * PneumaticClass;
ControllerClass *controllerClass;
DriveSubsystem* driveSubsystem;
void Robot::RobotInit() {
  ColorClass = new  Color();
  FeederClass = new Feeder();
  TurretClass = new Turret();
  ShooterClass = new Shooter();
  spindexerClass = new Spindexer();
  driveSubsystem = new DriveSubsystem();
  IntakeClass = new Intake();
  PneumaticClass = new Pneumatics();
  controllerClass = new ControllerClass;
  IntakeClass->InitIntake();
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  frc2::CommandScheduler::GetInstance().Run();
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  m_autonomousCommand = m_container.GetAutonomousCommand();

  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {
  controllerClass->Update();
  FeederClass->runFeeder(controllerClass->bXButtonPressedC1, controllerClass->bYButtonPressedC1);
  TurretClass->runTurret(controllerClass->bLeftBumperC1, controllerClass->bRightBumperC1);
  ShooterClass->runShooter(controllerClass->dLeftTriggerC1, controllerClass->dRightTriggerC1);
  IntakeClass->RunIntake(controllerClass->bStartButtonC1, controllerClass->bBackButtonPressedC1);
  driveSubsystem->TankDrive(controllerClass->dLeftStickYC1, controllerClass->dRightStickYC1);
  spindexerClass->runSpindexer(controllerClass->bAButtonPressedC1, controllerClass->bBButtonPressedC1);
  ColorClass->runColorWheel(controllerClass->bAButtonPressedC2, controllerClass->bBButtonPressedC2);
  PneumaticClass->pColor(controllerClass->bAButtonRawC1);
  PneumaticClass->pIntake(controllerClass->bLeftBumperC2,controllerClass->bRightBumperC2);
  TurretClass->autoRotate(controllerClass->bStartButtonC1);
}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {
  //DriveClass->DriveTest();
}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
