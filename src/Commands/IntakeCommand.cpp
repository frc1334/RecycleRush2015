#include "IntakeCommand.h"

IntakeCommand::IntakeCommand()
{
	Requires(pickupSubsystem);
}

// Called just before this Command runs the first time
void IntakeCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void IntakeCommand::Execute()
{
	pickupSubsystem->Intake(oi->GetDriverIntakeDirection(),
			oi->GetDriverIntakeSpeed(), oi->GetDriverIntakeSpeed());
	pickupSubsystem->intakeSolenoid.Set(oi->GetDriverIntakeToggle());
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void IntakeCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeCommand::Interrupted()
{

}
