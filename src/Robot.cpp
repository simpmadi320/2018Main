#include <Commands/Waiter.h>
#include "Robot.h"

#include "Commands/AutonomousForward.h"
#include "Commands/AutonomousGripper.h"

/**
 *
 */

Robot::~Robot()
{
	delete this->pDriveWithJoystick;
	delete this->pDefaultAutoCommand;
	delete this->pMyAutoCommand;

	return;
}

/**
 *
 */

void Robot::RobotInit()
{
	std::cout << "[Robot] Initialized" << std::endl;

	// instantiate the commands
	this->pDriveWithJoystick = new DriveWithJoystick();
	this->pDefaultAutoCommand = new ExampleCommand();
	this->pMyAutoCommand = new MyAutoCommand();

	// Setup smartdashboard autonomous options
	m_chooser.AddDefault("Default Auto", pDefaultAutoCommand);
	m_chooser.AddObject("My Auto", pMyAutoCommand);
	frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

	return;
}

/**
 *
 */

void Robot::DisabledInit()
{
	return;
}

/**
 *
 */

void Robot::DisabledPeriodic()
{
	frc::Scheduler::GetInstance()->Run();

	return;
}

/**
 *
 */

void Robot::AutonomousInit()
{
	std::cout << "[Robot] Autonomous Initialized" << std::endl;

//	std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", "Default");
//	std::cout << "[Robot] Auto Selected: " << autoSelected << std::endl;
//
//	pAutonomousCommand = m_chooser.GetSelected();
//
//	if (pAutonomousCommand != nullptr)
//	{
//		std::cout << "[Robot] Starting autonomous" << std::endl;
//		pAutonomousCommand->Start();
//	}
//	else
//	{
//		std::cout << "Autonomous Command is null!" << std::endl;
//	}

	//::Scheduler::GetInstance()->AddCommand( new WaitCommand(5.0));
	::Scheduler::GetInstance()->AddCommand( new AutonomousForward( 4.0 , 0.6 , AUTO_WAIT_TIME) );
	// TODO: Add command for mast raise
	::Scheduler::GetInstance()->AddCommand( new AutonomousGripper( AutonomousGripper::GRIPPER_CLOSED ) );

	return;
}

/**
 *
 */

void Robot::AutonomousPeriodic()
{
	frc::Scheduler::GetInstance()->Run();

	return;
}

/**
 *
 */

void Robot::TeleopInit()
{
	std::cout << "[Robot] Teleop Initialized" << std::endl;

	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (pAutonomousCommand != nullptr)
	{
		pAutonomousCommand->Cancel();
		pAutonomousCommand = nullptr;
	}

	if (pDriveWithJoystick != nullptr)
	{
		std::cout << "[Robot] Starting DriveWithJoystick" << std::endl;
		//pDriveWithJoystick->Start();
	}
	else
	{
		std::cout << "[Robot] DriveWithJoystick is null!" << std::endl;
	}

	return;
}

/**
 *
 */

void Robot::TeleopPeriodic()
{
	//std::cout << "[Robot] Running Scheduler" << std::endl;

	frc::Scheduler::GetInstance()->Run();

	return;
}

/**
 *
 */

void Robot::TestPeriodic()
{
	std::cout << "[Robot] TestPeriodic" << std::endl;

	return;
}

/**
 *
 */

START_ROBOT_CLASS(Robot)

