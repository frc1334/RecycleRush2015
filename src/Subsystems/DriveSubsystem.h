#ifndef DRIVE_SUBSYSTEM_H
#define DRIVE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveSubsystem: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon DriveLeft1, DriveLeft2, DriveRight1, DriveRight2;
	Solenoid ShiftSolenoid;
public:
	DriveSubsystem();
	void InitDefaultCommand();
	void Drive(float speed, float turn);
	void SetShiftState(bool state);
	void Reset();
};

#endif
