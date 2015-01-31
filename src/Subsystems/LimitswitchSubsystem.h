#ifndef LIMIT_SWITCH_SUBSYSTEM_H
#define LIMIT_SWITCH_SUBSYSTEM_H


#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

class LimitswitchSubsystem: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DigitalInput Tier1,Tier2,Tier3,Tier4,Tier5,Tier6,Tier7;

public:
	LimitswitchSubsystem();
	void InitDefaultCommand();
	void Reset();
};



#endif
