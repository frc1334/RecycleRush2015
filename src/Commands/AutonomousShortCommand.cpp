#include "AutonomousDriveCommand.h"
#include "AutonomousShortCommand.h"

AutonomousShortCommand::AutonomousShortCommand()
{
	AddSequential(new AutonomousDriveCommand(1.0, 0.5, 0.0));
	AddParallel(new AutonomousIntakeCommand(0,0,0, true));
}
