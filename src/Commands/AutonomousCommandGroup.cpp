
#include "AutonomousCommandGroup.h"
#include "AutonomousDriveCommand.h"


AutonomousCommandGroup::AutonomousCommandGroup()
{
	AddSequential(new AutonomousDriveCommand(3.0, 0.5, 0.0));

}

