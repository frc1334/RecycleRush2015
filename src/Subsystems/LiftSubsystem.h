#ifndef LIFT_SUBSYSTEM_H
#define LIFT_SUBSYSTEM_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"
#include <stdio.h>
using namespace std;

class LiftSubsystem: public PIDSubsystem
{
private:
	double p = 1;
	double i = 0.4;
	double d = 0.0;


	//DigitalInput limitSwitch;
	Talon left,right;

	Encoder *beltEncoderL,*beltEncoderR;
	DigitalInput *limitSwitchL, *limitSwitchR;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	LiftSubsystem();

	void InitDefaultCommand();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void Lift(float speed);
	void Reset();

};

#endif
