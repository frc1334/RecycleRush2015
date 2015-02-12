#include "PickupSubsystem.h"
#include "../RobotMap.h"




PickupSubsystem::PickupSubsystem() :
		Subsystem("PickupSubsystem"), intakeRight(INTAKE_MOTOR_RIGHT), intakeLeft(INTAKE_MOTOR_LEFT), intakeSolenoid(INTAKE_SOLENOID)
{

}

void PickupSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void PickupSubsystem::SetPosition(bool position)
{
	intakeSolenoid.Set(position);
}

void PickupSubsystem::Intake(float x, float y, float direction)
{

	intakeRight.Set(y);
	intakeLeft.Set(-y);
}
void PickupSubsystem::Reset()
{
}
