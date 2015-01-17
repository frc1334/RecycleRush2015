#include "ElevatorSubsystem.h"
#include "../RobotMap.h"

ElevatorSubsystem::ElevatorSubsystem() :
		Subsystem("ElevatorSubsystem"),Elevator(ELEVATOR)
{

}
void ElevatorSubsystem::Lift(float speed)
{
	Elevator.Set(speed);
}
void ElevatorSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
void ElevatorSubsystem::Reset()
{
}
