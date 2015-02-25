#ifndef LIFT_SUBSYSTEM_H
#define LIFT_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

class LiftSubsystem: public PIDSubsystem
{
private:
	double p = 1.0;
	double i = 0.0;
	double d = 0.0;


	//DigitalInput limitSwitch;
	Talon LiftMotorL,LiftMotorR;
	Encoder *beltEncoderL,*beltEncoderR;

	double distanceRaw = (beltEncoderL->GetRaw()+beltEncoderR->GetRaw())/2;
	double distance = (beltEncoderL->GetDistance()+beltEncoderR->GetDistance())/2;
	double period = (beltEncoderL->GetPeriod()+beltEncoderR->GetPeriod())/2;
	double rate = (beltEncoderL->GetRate()+beltEncoderR->GetRate())/2;
	bool directionL = beltEncoderL->GetDirection();
	bool directionR = beltEncoderR->GetDirection();
	bool stoppedL = beltEncoderL->GetStopped();
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:


	LiftSubsystem();

	void InitDefaultCommand();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void Reset();

};

#endif
