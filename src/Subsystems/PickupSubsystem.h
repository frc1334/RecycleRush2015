#ifndef PICKUP_SUBSYSTEM_H
#define PICKUP_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

class PickupSubsystem: public Subsystem
{
private:

	Talon intakeRight, intakeLeft;
	Solenoid intakeSolenoid;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	PickupSubsystem();
	void InitDefaultCommand();
	void SetPosition(bool position);
	void Intake(float x, float y, float direction);
	void Reset();

};

#endif
