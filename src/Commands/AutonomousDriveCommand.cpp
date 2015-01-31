
#include "AutonomousDriveCommand.h"

AutonomousDriveCommand::AutonomousDriveCommand(double seconds, float speed, float turn)
	: delay(), seconds(seconds), speed(speed), turn(turn)
{
	Requires(driveSubsystem);
}

void AutonomousDriveCommand::Initialize()
{
	delay.Reset();
	delay.Start();
	driveSubsystem->Drive(speed, turn);
}

void AutonomousDriveCommand::Execute()
{
}

bool AutonomousDriveCommand::IsFinished()
{
	return delay.HasPeriodPassed(seconds);
}

void AutonomousDriveCommand::End()
{
	driveSubsystem->Drive(0.0f, 0.0f);
	delay.Stop();
}

void AutonomousDriveCommand::Interrupted()
{
	delay.Reset();
	delay.Stop();
}
