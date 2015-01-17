#ifndef LIMIT_SWITCH_SUBSYSTEM_H
#define LIMIT_SWITCH_SUBSYSTEM_H


#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"

class LimitswitchSubsystem: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities


public:
	LimitswitchSubsystem();
	void InitDefaultCommand();
	void Reset();
};



#endif
