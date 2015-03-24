#include "AutonomousZeroCommand.h"

AutonomousZeroCommand::AutonomousZeroCommand()
{
	Requires(pidElevatorSubsystem);
	timer = new Timer();
	timer->Stop();
	timer->Reset();
}
void AutonomousZeroCommand::Initialize()
{
	timer->Stop();
	timer->Reset();
}
void AutonomousZeroCommand::Execute()
{
	pidElevatorSubsystem->NSLift(-1);
}
bool AutonomousZeroCommand::IsFinished()
{
	return timer->HasPeriodPassed(10.0);
}
void AutonomousZeroCommand::End()
{
	pidElevatorSubsystem->NSLift(0);
	pidElevatorSubsystem->Reset();
}

void AutonomousZeroCommand::Interrupted()
{
}
