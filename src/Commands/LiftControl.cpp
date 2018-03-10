#include "LiftControl.h"

#include "../RobotMap.h"

#include <iostream>


LiftControl::LiftControl()
{
	std::cout << "[LiftControl] Constructed" << std::endl;

	if (CommandBase::pDriveTrain != nullptr)
	{
		Requires(CommandBase::pLiftMast);
	}
	else
	{
		std::cout << "[LiftControl] driveTrain is null!" << std::endl;
	}


	return;
}


void LiftControl::Initialize()
{
	std::cout << "[LiftControl] Initialized" << std::endl;


	return;
}





void LiftControl::Execute()
{
//	::SmartDashboard::PutNumber("Selected TalonID:", this->m_selectedTalonID);
//	::SmartDashboard::PutString("Y+A = Select Talon", "Right Joy for +ve, -ve power");

	frc::XboxController* pJoyDriver = CommandBase::pOI->GetJoystickDrive();

	// Lift motor speed controlled by LEFT joystick on DRIVER "y" axis (forward and back)
	double liftSpeedAndDirection = pJoyDriver->GetY(XboxController::kLeftHand);

//	const float SPEEDLIMIT = 0.5;
//	if ( liftSpeedAndDirection > SPEEDLIMIT )
//	{
//		liftSpeedAndDirection = SPEEDLIMIT;
//	}

//	const double SPEEDRATIO = 0.1;
//	liftSpeedAndDirection *= SPEEDRATIO;

	CommandBase::pLiftMast->DEBUG_SetMotorSpeed(liftSpeedAndDirection);

	::SmartDashboard::PutNumber("LiftControl LiftSpeed:", liftSpeedAndDirection);



	return;
}


bool LiftControl::IsFinished()
{
	return false;
}


void LiftControl::End()
{
	return;
}


void LiftControl::Interrupted()
{
	return;
}

