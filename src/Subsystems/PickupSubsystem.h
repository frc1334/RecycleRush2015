#ifndef PICKUP_SUBSYSTEM_H
#define PICKUP_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

class PickupSubsystem: public Subsystem
{
private:

	Talon BeltMotorLeft, BeltMotorRight;
	Solenoid WheelSolenoidLeft, WheelSolenoidRight;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	PickupSubsystem();
	void InitDefaultCommand();
	void Open(float Speed);
	void Close(float Speed);
	void Reset();

};

#endif
