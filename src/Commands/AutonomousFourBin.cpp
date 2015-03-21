#include "AutonomousFourBin.h"
#include "AutonomousDriveCommand.h"
#include "AutonomousElevatorCommand.h"
#include "AutonomousIntakeCommand.h"
#include "AutonomousWinchCommand.h"

AutonomousFourBin::AutonomousFourBin()
{
	AddSequential(new AutonomousDriveCommand(.5f, -0.5f, 0));
	AddSequential(new AutonomousDriveCommand(2, 0.5f, 0));
	AddParallel(new AutonomousDriveCommand(1, 0, 0));
	AddParallel(new AutonomousWinchCommand(1, .5f));
}
