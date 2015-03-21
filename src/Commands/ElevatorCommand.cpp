
#include "ElevatorCommand.h"

ElevatorCommand::ElevatorCommand()
{
	Requires(pidElevatorSubsystem);
}
void ElevatorCommand::Initialize()
{

}
void ElevatorCommand::Execute()
{
	//pidElevatorSubsystem->UsePIDOutput(oi->GetOperatorElevator());
	pidElevatorSubsystem->Lift(oi->GetOperatorElevator());
	pidElevatorSubsystem->NSLift(oi->GetOperatorElevator());
	//if(oi->GetOperatorMoveTotes())
		//pidElevatorSubsystem->SetSetpoint(1.0);
}
bool ElevatorCommand::IsFinished()
{
	return false;
}
void ElevatorCommand::End()
{

}
void ElevatorCommand::Interrupted()
{

}

