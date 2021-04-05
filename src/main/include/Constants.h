// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/trajectory/constraint/DifferentialDriveKinematicsConstraint.h>
#include <units/acceleration.h>
#include <units/length.h>
#include <units/time.h>
#include <units/velocity.h>
#include <units/voltage.h>
#include <wpi/math>


namespace DriveConstants {
constexpr int kLeftMotor1Port = 11;
constexpr int kLeftMotor2Port = 12;
constexpr int kRightMotor1Port = 13;
constexpr int kRightMotor2Port = 14;

constexpr int kLeftEncoderPorts[]{0, 1};
constexpr int kRightEncoderPorts[]{2, 3};
constexpr bool kLeftEncoderReversed = false;
constexpr bool kRightEncoderReversed = true;

constexpr auto kTrackwidth = 0.695325_m;
extern const frc::DifferentialDriveKinematics kDriveKinematics;

constexpr int kEncoderCPR = 2048;
constexpr double kWheelDiameterInches = 6;
constexpr double kEncoderDistancePerPulse =  //FIX
    (kWheelDiameterInches * wpi::math::pi) / static_cast<double>(kEncoderCPR);

// These are example values only - DO NOT USE THESE FOR YOUR OWN ROBOT!
// These characterization values MUST be determined either experimentally or
// theoretically for *your* robot's drive. The Robot Characterization
// Toolsuite provides a convenient tool for obtaining these values for your
// robot.
constexpr auto ks = 0.488_V;
constexpr auto kv = 4.14 * 1_V * 1_s / 1_m;
constexpr auto ka = 0.275 * 1_V * 1_s * 1_s / 1_m; 

// Example value only - as above, this must be tuned for your drive!
constexpr double kPDriveVel = 0.24;
}  // namespace DriveConstants

namespace AutoConstants {
constexpr auto kMaxSpeed = 5_mps;
constexpr auto kMaxAcceleration = 2.5_mps_sq;

// Reasonable baseline values for a RAMSETE follower in units of meters and
// seconds
constexpr double kRamseteB = 2.0;
constexpr double kRamseteZeta = 0.7;
}  // namespace AutoConstants

namespace OIConstants {
constexpr int kDriverControllerPort = 0;
}  // namespace OIConstants