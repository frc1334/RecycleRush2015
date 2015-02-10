/*
 * ElevatorCommand.cpp
 *
 *  Created on: Feb 9, 2015
 *      Author: p
 */

#include "ElevatorCommand.h"

ElevatorCommand::ElevatorCommand()
{
	Requires(elevatorSubsystem);
}
void ElevatorCommand::Initialize()
{

}
void ElevatorCommand::Execute()
{
	elevatorSubsystem->Lift(oi->GetOperatorElevator());
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

