#include "ElevatorSubsystem.h"
#include "../RobotMap.h"

ElevatorSubsystem::ElevatorSubsystem() :
		Subsystem("ElevatorSubsystem"),left(ELEVATOR_LEFT),right(ELEVATOR_RIGHT)
{

}
/**void ElevatorSubsystem::Lift(float speed)
{
	left.Set(speed);
	right.Set(-speed);
}*/
void ElevatorSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
void ElevatorSubsystem::Reset()
{
}
