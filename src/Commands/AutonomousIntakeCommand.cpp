
#include "AutonomousIntakeCommand.h"

AutonomousIntakeCommand::AutonomousIntakeCommand(double seconds, float x, float y)
	: delay(), seconds(seconds), x(x), y(y)
{
	Requires(pickupSubsystem);
}

void AutonomousIntakeCommand::Initialize()
{
	delay.Reset();
	delay.Start();
}

void AutonomousIntakeCommand::Execute()
{
	pickupSubsystem->Intake(x,y,0);
}

bool AutonomousIntakeCommand::IsFinished()
{

	return delay.HasPeriodPassed(seconds);
}

void AutonomousIntakeCommand::End()
{
	delay.Stop();
	delay.Reset();
}

void AutonomousIntakeCommand::Interrupted()
{
	delay.Stop();
	delay.Reset();
}
