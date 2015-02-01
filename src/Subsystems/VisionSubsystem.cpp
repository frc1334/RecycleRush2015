#include "VisionSubsystem.h"
#include "../RobotMap.h"

VisionSubsystem::VisionSubsystem() :
		Subsystem("VisionSubsystem"), Camera1(CAMERA1)
{

}

void VisionSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void VisionSubsystem::Reset()
{
}
