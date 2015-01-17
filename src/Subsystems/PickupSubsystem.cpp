#include "PickupSubsystem.h"
#include "../RobotMap.h"

PickupSubsystem::PickupSubsystem() :
		Subsystem("PickupSubsystem")
{

}

void PickupSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void PickupSubsystem::Reset()
{
}
