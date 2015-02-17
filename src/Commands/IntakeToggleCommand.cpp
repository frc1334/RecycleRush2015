#include "IntakeToggleCommand.h"

IntakeToggleCommand::IntakeToggleCommand()
{
	Requires(pickupSubsystem);
}

// Called just before this Command runs the first time
void IntakeToggleCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void IntakeToggleCommand::Execute()
{
	if(oi->GetDriverIntakeToggle())
		pickupSubsystem->SetPosition(!oi->GetDriverIntakeToggle());
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeToggleCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void IntakeToggleCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeToggleCommand::Interrupted()
{

}
