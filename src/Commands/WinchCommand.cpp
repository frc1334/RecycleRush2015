#include "WinchCommand.h"
#include <iostream>

using namespace std;

WinchCommand::WinchCommand()
{
	Requires(canBurglerSubsystem);

}

// Called just before this Command runs the first time
void WinchCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WinchCommand::Execute()
{

	canBurglerSubsystem->Winch(oi->GetOperatorWinch());
}

// Make this return true when this Command no longer needs to run execute()
bool WinchCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void WinchCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchCommand::Interrupted()
{

}
