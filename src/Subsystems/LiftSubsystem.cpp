#include "LiftSubsystem.h"
#include "../RobotMap.h"

LiftSubsystem::LiftSubsystem() :
		Subsystem("LiftSubsystem"), LiftMotor1(LIFTMOTOR1), LiftMotor2(LIFTMOTOR2)
{

}

void LiftSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
// (maybe) Raises the platform
void LiftSubsystem::Raise(float Speed)
{
	Speed = 1;
LiftMotor1.Set(Speed);
LiftMotor2.Set(Speed * -1);
}
// (maybe) Lowers the platform
void LiftSubsystem::Lower(float Speed)
{
	Speed = -1;
LiftMotor1.Set(Speed);
LiftMotor2.Set(Speed * -1);
}
// OnRelease for stopping the motors
void LiftSubsystem::OnRelease(float Speed)
{
	Speed = 0;
}

void LiftSubsystem::Reset()
{
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

