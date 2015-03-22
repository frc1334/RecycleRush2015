#ifndef DRIVE_COMMAND_H
#define DRIVE_COMMAND_H

#include "../CommandBase.h"
#include "WPILib.h"

class EZElevatorCommand: public CommandBase
{
private:

public:
	EZElevatorCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
