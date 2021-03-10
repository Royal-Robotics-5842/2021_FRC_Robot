// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"


using namespace frc;
using namespace frc2;

RobotContainer::RobotContainer() : m_autonomousCommand(&m_Drivesubsystem) {
  // Initialize all of your commands and subsystems here
  Controller1 = new XboxController(0);
  Controller2 = new XboxController(1);
  
 // m_subsystem = new DriveSubsystem();

  // Configure the button bindings
  ConfigureButtonBindings();

  m_Drivesubsystem.SetDefaultCommand(frc2::RunCommand(
      [this] {
        m_Drivesubsystem.TankDrive(
            Controller1->GetY(frc::GenericHID::kLeftHand),
            Controller1->GetY(frc::GenericHID::kRightHand));
      },
      {&m_Drivesubsystem}));
}

void RobotContainer::ConfigureButtonBindings() {
  
} 

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // Create a voltage constraint to ensure we don't accelerate too fast
  frc::DifferentialDriveVoltageConstraint autoVoltageConstraint(
      frc::SimpleMotorFeedforward<units::meters>(
          DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
      DriveConstants::kDriveKinematics, 13_V);

  // Set up config for trajectory
  frc::TrajectoryConfig config(AutoConstants::kMaxSpeed,AutoConstants::kMaxAcceleration);
  //config.SetReversed(true);
  // Add kinematics to ensure max speed is actually obeyed
  config.SetKinematics(DriveConstants::kDriveKinematics);
  // Apply the voltage constraint
  config.AddConstraint(autoVoltageConstraint);

  // An example trajectory to follow.  All units in meters.
 wpi::SmallString<64> deployDirectory;
frc::filesystem::GetDeployDirectory(deployDirectory);
// wpi::sys::path::append(deployDirectory, "paths");
// wpi::sys::path::append(deployDirectory,  "tiny.wpilib.json");

//frc::Trajectory exampletrajectory = frc::TrajectoryUtil::FromPathweaverJson(deployDirectory);
auto exampletrajectory = frc::TrajectoryGenerator::GenerateTrajectory(
 // Start at the origin facing the +X direction
  frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),
 // Pass through these two interior waypoints, making an 's' curve path
 {frc::Translation2d(1_m, 0_m), frc::Translation2d(2_m, 0_m)},
 // End 3 meters straight ahead of where we started, facing forward
 frc::Pose2d(2_m, 0_m, frc::Rotation2d(0_deg)),
 // Pass the config
 config);

frc2::RamseteCommand ramseteCommand(exampletrajectory, [this]() { return m_Drivesubsystem.GetPose(); },
      frc::RamseteController(AutoConstants::kRamseteB,
                             AutoConstants::kRamseteZeta),
      frc::SimpleMotorFeedforward<units::meters>(
          DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
      DriveConstants::kDriveKinematics,
      [this] { return m_Drivesubsystem.GetWheelSpeeds(); },
      frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
      frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
      [this](auto left, auto right) { m_Drivesubsystem.TankDriveVolts(left,right); },
      {&m_Drivesubsystem});

  // Reset odometry to the starting pose of the trajectory.
  m_Drivesubsystem.ResetOdometry(exampletrajectory.InitialPose());

  // no auto
  return new frc2::SequentialCommandGroup(
      std::move(ramseteCommand),
      frc2::InstantCommand([this] { m_Drivesubsystem.TankDriveVolts(0_V, 0_V); }, {}));
}
