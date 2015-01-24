/*
 * AutonomousDriveCommand.h
 *
 *  Created on: Jan 24, 2015
 *      Author: p
 */

#ifndef AUTONOMOUSDRIVECOMMAND_H
#define AUTONOMOUSDRIVECOMMAND_H
#include "../CommandBase.h"

class AutonomousDriveCommand : public CommandBase
{
private:
	Timer delay;
	double seconds;
	float speed, turn;

public:
	AutonomousDriveCommand(double seconds, float speed, float turn);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
