/*
 * CanBurglerSubsystem.cpp
 *
 *  Created on: Mar 20, 2015
 *      Author: Gabriel
 */
#include "CanBurglerSubsystem.h"
#include "../RobotMap.h"

CanBurglerSubsystem::CanBurglerSubsystem() :
		Subsystem("CanBurglerSubsystem"), winch(WINCH)
{
	winchstop = new DigitalInput(WINCHSTOP);

}

void CanBurglerSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
void CanBurglerSubsystem::Winch(float speed)
{
	winch.Set(speed);
	if (winchstop->Get())
	{
		winch.Set(0);
	}
}

void CanBurglerSubsystem::Reset()
{
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

