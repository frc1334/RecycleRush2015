#include "LiftSubsystem.h"
#include "../RobotMap.h"


//Subsystem to move the elevator

LiftSubsystem::LiftSubsystem() :Subsystem("LiftSubsystem"), LiftMotor1(ELEVATOR_LEFT), LiftMotor2(ELEVATOR_RIGHT),beltEncoder1(BELT_LEFT),beltEncoder2(BELT_RIGHT)
{
	beltEncoder1.SetMaxPeriod(.1);
	beltEncoder2.SetMaxPeriod(.1);
	beltEncoder1.SetMinRate(10);
	beltEncoder2.SetMinRate(10);
	beltEncoder1.SetDistancePerPulse(5);
	beltEncoder2.SetDistancePerPulse(5);
	beltEncoder2.SetReverseDirection(true);
	beltEncoder1.SetSamplesToAverage(7);
	beltEncoder2.SetSamplesToAverage(7);

}

void LiftSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

//Raises the elevator (Maybe)
void LiftSubsystem::Raise(float Speed)
{
	Speed = 1;
LiftMotor1.Set(Speed);
LiftMotor2.Set(Speed *-1);
}

//Lowers the elevator (Maybe)
void LiftSubsystem::Lower(float Speed)
{
	Speed = -1;
LiftMotor1.Set(Speed);
LiftMotor2.Set(Speed *-1);
}

//Sets the elevator to stationary (For use on button release)
void LiftSubsystem::OnRelease(float Speed)
{
	Speed = 0;
LiftMotor1.Set(Speed);
LiftMotor2.Set(Speed);

}

void LiftSubsystem::Reset()
{
}
