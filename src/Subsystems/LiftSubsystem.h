#ifndef LIFT_SUBSYSTEM_H
#define LIFT_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

class LiftSubsystem: public Subsystem
{
private:
	DigitalInput limitSwitch;
	Talon LiftMotor1,LiftMotor2;
	Encoder beltEncoder;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	LiftSubsystem();
	void InitDefaultCommand();
	void Raise(float Speed);
	void Lower(float Speed);
	void OnRelease(float Speed);
	void Reset();

};

#endif
