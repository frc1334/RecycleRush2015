
#ifndef ELEVATORCOMMAND_H
#define ELEVATORCOMMAND_H

#include "../CommandBase.h"
#include "WPILib.h"

class ElevatorCommand: public CommandBase
{
public:
	ElevatorCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
