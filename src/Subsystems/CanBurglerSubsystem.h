/*
 * CanBurglerSubsystem.h
 *
 *  Created on: Mar 20, 2015
 *      Author: Gabriel
 */

#ifndef CANBURGLERSUBSYSTEM_H
#define CANBURGLERSUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

class CanBurglerSubsystem : public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	Talon winch;
	DigitalInput* winchstop;

public:
	CanBurglerSubsystem();
	void InitDefaultCommand();
	void Winch(float speed);
	void Reset();
};

#endif /* SRC_SUBSYSTEMS_CANBURGLERSUBSYSTEM_H_ */
