#ifndef LIFT_SUBSYSTEM_H
#define LIFT_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

class LiftSubsystem: public Subsystem
{
private:
	//DigitalInput limitSwitch;
	Talon LiftMotor1,LiftMotor2;
	Encoder beltEncoder1,beltEncoder2;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	LiftSubsystem();
	double distance = (beltEncoder1.GetRaw()+beltEncoder2.GetRaw())/2;
	double distance = (beltEncoder1.GetDistance()+beltEncoder2.GetDistance())/2;
	double period = (beltEncoder1.GetPeriod()+beltEncoder2.GetPeriod())/2;
	double rate = (beltEncoder1.GetRate()+beltEncoder2.GetRate())/2;
	bool direction1 = beltEncoder1.GetDirection();
	bool direction2 = beltEncoder2.GetDirection();
	bool stopped = beltEncoder1.GetStopped();
	void InitDefaultCommand();
	void Raise(float Speed);
	void Lower(float Speed);
	void OnRelease(float Speed);
	void Reset();

};

#endif
