/*
 * AutonomousDriveCommand.h
 *
 *  Created on: Jan 24, 2015
 *      Author: p
 */

#ifndef AUTONOMOUSWINCHCOMMAND_H
#define AUTONOMOUSWINCHCOMMAND_H
#include "../CommandBase.h"

class AutonomousWinchCommand : public CommandBase
{
private:
	Timer delay;
	double seconds;
	float speed;

public:
	AutonomousWinchCommand(double seconds, float speed);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
