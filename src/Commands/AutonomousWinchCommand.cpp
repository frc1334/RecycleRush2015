#include "AutonomousWinchCommand.h"

AutonomousWinchCommand::AutonomousWinchCommand(double seconds, float speed) :
		delay(), seconds(seconds), speed(speed)
{
	Requires(canBurglerSubsystem);
}

void AutonomousWinchCommand::Initialize()
{
	delay.Reset();
	delay.Start();
	canBurglerSubsystem->Winch(speed);
}

void AutonomousWinchCommand::Execute()
{
}

bool AutonomousWinchCommand::IsFinished()
{
	return delay.HasPeriodPassed(seconds);
}

void AutonomousWinchCommand::End()
{
	canBurglerSubsystem->Winch(0.0f);
	delay.Stop();
}

void AutonomousWinchCommand::Interrupted()
{
	delay.Reset();
	delay.Stop();
}
