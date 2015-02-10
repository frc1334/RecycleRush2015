#ifndef ELEVATOR_SUBSYSTEM_H
#define ELEVATOR_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

class ElevatorSubsystem: public Subsystem
{
private:
	Talon left,right;


public:
	ElevatorSubsystem();
	void Lift(float speed);
	void InitDefaultCommand();
	void Reset();
};




#endif
