
#include "AutonomousCommandGroup.h"
#include "AutonomousDriveCommand.h"
#include "../RobotMap.h"

AutonomousCommandGroup::AutonomousCommandGroup()
{
	AddSequential(new AutonomousDriveCommand(2.0, 0.5, 0.0));

}

