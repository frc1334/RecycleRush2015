
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
	pidElevatorSubsystem->UsePIDOutput(oi->GetOperatorElevator());
	//elevatorSubsystem->Lift(oi->GetOperatorElevator());
	//pidElevatorSubsystem->Lift(oi->GetOperatorElevator());
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

