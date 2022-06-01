// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <iostream>
#include <string>
#include "WPILibVersion.h"
#include "cameraserver/CameraServer.h"
#include <frc/AnalogGyro.h>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DriverStation.h>
#include <frc/Joystick.h>
#include <frc/GenericHID.h>
#include <frc/XboxController.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/drive/MecanumDrive.h>
#include <frc/DigitalInput.h>
#include <frc/Solenoid.h>
#include <frc/DoubleSolenoid.h>
#include <frc/Compressor.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>
//Paul 11/10/21 "I have no idea what's happening"
#include <AHRS.h>
#include <rev/CANSparkMax.h>
#include <ctre/Phoenix.h>
#include <Intake.h>
#include <Shooter.h>
#include <Swiss.h>

enum CANIDS {
    SHOOTER = 5,
    INTAKE = 6,
    SWISS = 7
  };

enum CONTROLLERS {
  xbox = 0
};

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  frc::XboxController *m_xbox;
  Intake *m_intake;
  Shooter *m_shooter;
  Swiss *m_swiss;
};
