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
	if(y > 0.25 || y < -0.25){
		if(x < -0.5f || x > 0.5){
				intakeLeft.Set(x);
				intakeRight.Set(x);
		}
		else{
			intakeLeft.Set(-y);
			intakeRight.Set(y);
		}
	}
	else{
			intakeLeft.Set(0);
			intakeRight.Set(0);
		}
	/*else
	{
		intakeRight.Set(y);
		intakeLeft.Set(-y);
	}*/

}
void PickupSubsystem::Reset()
{
}
