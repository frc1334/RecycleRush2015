#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
DriveSubsystem* CommandBase::driveSubsystem= NULL;
CanBurglerSubsystem* CommandBase::canBurglerSubsystem=NULL;
PickupSubsystem* CommandBase::pickupSubsystem=NULL;
LiftSubsystem* CommandBase::pidElevatorSubsystem=NULL;
OI* CommandBase::oi = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	oi = new OI();
	driveSubsystem = new DriveSubsystem();
	canBurglerSubsystem = new CanBurglerSubsystem();
	pidElevatorSubsystem = new LiftSubsystem();
	pickupSubsystem = new PickupSubsystem();

}
