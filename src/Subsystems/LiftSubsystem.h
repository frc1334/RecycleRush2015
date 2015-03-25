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
	float setpointR = 0, setpointL = 0;
	Talon left, right;
	Encoder *beltEncoderL, *beltEncoderR;
	DigitalInput *limitSwitchL, *limitSwitchR;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	LiftSubsystem();
	void InitDefaultCommand();
	void EZLift(float speed);
	void NSLift(float speed);
	void Lift(float position);
	void Reset();

};

#endif
