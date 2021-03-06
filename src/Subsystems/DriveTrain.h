#ifndef _DRIVETRAIN_HG_
#define _DRIVETRAIN_HG_

#include <WPILib.h>
#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <SpeedControllerGroup.h>
#include <Drive/DifferentialDrive.h>
#include "../RobotMap.h"

#include <iostream>

/**
 *
 */

class DriveTrain: public frc::Subsystem
{
public:
	DriveTrain();
	~DriveTrain();
	void InitDefaultCommand() override;

	// Original basic example drive, passing joystick. Calls ArcadeDrive()
	void Drive(XboxController* joystick);
	// These are the same as the DifferentialDrive class:
	void ArcadeDrive( double xSpeed, double zRotation );
	void CurvatureDrive( double xSpeed, double zRotation, bool isQuickTurn );
	void TankDrive( double leftSpeed, double rightSpeed );

	void Reset();

	void getEncoderPosition(double &leftEncoder, double &rightEncoder);
	void getEncoderVelocity(double &leftEncoder, double &rightEncoder);

	void resetEncoder(bool bLeft, bool bRight);

	enum eMotorID
	{
		LEFT_FRONT,
		LEFT_REAR,
		RIGHT_FRONT,
		RIGHT_REAR
	};
	// This is used to get the information directly from the motor
	double DEBUG_getEncoderPositionFromMotorID( eMotorID motorID );
	double DEBUG_getEncoderVelocityFromMotorID( eMotorID motorID );

private:
	can::WPI_TalonSRX* pLeftFrontMotor;
	can::WPI_TalonSRX* pLeftRearMotor;
	can::WPI_TalonSRX* pRightFrontMotor;
	can::WPI_TalonSRX* pRightRearMotor;

	frc::SpeedControllerGroup* pLeftSpeedControllerGroup;
	frc::SpeedControllerGroup* pRightSpeedControllerGroup;

	frc::DifferentialDrive* pRobotDrive;
};

#endif


