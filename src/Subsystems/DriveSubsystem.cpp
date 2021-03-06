#include "DriveSubsystem.h"
#include "../RobotMap.h"

DriveSubsystem::DriveSubsystem() :
		Subsystem("DriveSubsystem"), DriveLeft1(LEFT1), DriveLeft2(LEFT2), DriveRight1(RIGHT1), DriveRight2(RIGHT2)
{

}

void DriveSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
void DriveSubsystem::Drive(float speedLeft, float speedRight, float turn)
{
	float speed = (speedLeft *-1) + speedRight;
	DriveLeft1.Set(-turn + speed);
	DriveLeft2.Set(-turn + speed);
	DriveRight1.Set(-turn - speed);
	DriveRight2.Set(-turn - speed);
}

void DriveSubsystem::Drive(float speed, float turn)
{

	DriveLeft1.Set(turn + speed);
	DriveLeft2.Set(turn + speed);
	DriveRight1.Set(turn - speed);
	DriveRight2.Set(turn - speed);
}


void DriveSubsystem::Reset()
{
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

