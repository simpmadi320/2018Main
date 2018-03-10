#include "CommandBase.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/PneumaticsControlModule.h"

/**
 *
 */

DriveTrain* CommandBase::pDriveTrain = NULL;
OI* CommandBase::pOI = NULL;
PneumaticsControlModule* CommandBase::pGripper = NULL;


CommandBase::CommandBase() : Command()
{
	std::cout << "[CommandBase] Constructed" << std::endl;

	this->init();

	return;
}

/**
 *
 */

CommandBase::~CommandBase()
{
	delete this->pDriveTrain;
	delete this->pGripper;
	delete this->pOI;

	return;
}

/**
 *
 */

CommandBase::CommandBase(char const *name) : Command(name)
{
	std::cout << "[CommandBase] Constructed with name: " << name << std::endl;

	return;
}

/**
 *
 */

void CommandBase::init()
{
	std::cout << "[CommandBase] Initialized" << std::endl;

	// Note: These aren't "this" because they are static,
	//	so there is only one instance of these variables in
	//	the CommandBase class. "this" pointers refer to
	//	regular variables that are created (and are unique)
	//	to the 'instance' of the object.

	if (CommandBase::pOI == nullptr)
	{
		CommandBase::pOI = new OI();
	}

	if (CommandBase::pDriveTrain == nullptr)
	{
		CommandBase::pDriveTrain = new DriveTrain();
	}

	if (CommandBase::pGripper == NULL)
	{
		CommandBase::pGripper = new PneumaticsControlModule();
	}
	return;
}


