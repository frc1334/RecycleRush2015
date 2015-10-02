#include "DriveCommand.h"
#include <iostream>

using namespace std;

DriveCommand::DriveCommand()
{
	Requires(driveSubsystem);
	shiftDown = shiftUp = false;
}

// Called just before this Command runs the first time
void DriveCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute()
{
	driveSubsystem->Drive(oi->GetDriveLeftTrigger(), oi->GetDriveRightTrigger(),
			oi->GetDriveSteering());
	//driveSubsystem->DriveRight();
	//driveSubsystem->Drive(-oi->GetDriveThrottle(), oi->GetDriveSteering());
	//cout <<"Trigger Values: " << oi->GetDriveThrottle() << endl;

	/*if (oi->GetShiftUp() && !shiftUp)
	 drivetrainsubsystem->SetShiftState(true);
	 if (oi->GetShiftDown() && !shiftDown)
	 drivetrainsubsystem->SetShiftState(false);
	 shiftUp = oi->GetShiftUp();
	 shiftDown = oi->GetShiftDown();*/
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCommand::Interrupted()
{

}
