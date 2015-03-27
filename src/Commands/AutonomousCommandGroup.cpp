
#include "AutonomousCommandGroup.h"
#include "AutonomousDriveCommand.h"
#include "AutonomousIntakeCommand.h"
#include "../RobotMap.h"

AutonomousCommandGroup::AutonomousCommandGroup()
{

	AddParallel(new AutonomousIntakeCommand(0,0,0, true));
	AddSequential(new AutonomousDriveCommand(2.0, 0.5, 0.0));

}

