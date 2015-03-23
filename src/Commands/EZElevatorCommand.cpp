#include "EZElevatorCommand.h"
#include <iostream>

using namespace std;

EZElevatorCommand::EZElevatorCommand()
{
	Requires(pidElevatorSubsystem);

}

// Called just before this Command runs the first time
void EZElevatorCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void EZElevatorCommand::Execute()
{
	//pidElevatorSubsystem->EZLift(oi->GetOperatorEZElevatorRB());
	//pidElevatorSubsystem->EZLift(oi->GetOperatorEZElevatorLB());

}

// Make this return true when this Command no longer needs to run execute()
bool EZElevatorCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void EZElevatorCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EZElevatorCommand::Interrupted()
{

}
