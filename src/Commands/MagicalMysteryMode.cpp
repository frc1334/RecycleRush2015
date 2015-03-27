#include "MagicalMysteryMode.h"
#include "AutonomousDriveCommand.h"
#include "AutonomousElevatorCommand.h"
#include "AutonomousIntakeCommand.h"

MagicalMysteryMode::MagicalMysteryMode()
{
	AddParallel(new AutonomousIntakeCommand(3, 1, 1,false));
	AddParallel(new AutonomousDriveCommand(4, 1, 1));
	AddSequential(new AutonomousDriveCommand(0,0, 0));
	AddParallel(new AutonomousIntakeCommand(0, 0, 0, false));
}
