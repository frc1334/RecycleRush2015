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
	double p = 1.0;
	double i = 0.1;
	double d = 0.1;


	//DigitalInput limitSwitch;
	Talon left,right;

	Encoder *beltEncoderL,*beltEncoderR;

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
