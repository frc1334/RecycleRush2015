#ifndef LIFT_SUBSYSTEM_H
#define LIFT_SUBSYSTEM_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"
#include <stdio.h>
using namespace std;

class LiftSubsystem : public Subsystem
{
private:
	float setpoint = 0;
	Talon left, right;
	Encoder *beltEncoderL, *beltEncoderR;
	DigitalInput *limitSwitchL, *limitSwitchR;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	LiftSubsystem();
	void InitDefaultCommand();
	void NSLift(float speed);
	void Lift(float speed);
	void Reset();

};

#endif
