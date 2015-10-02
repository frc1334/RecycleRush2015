#ifndef DRIVE_COMMAND_H
#define DRIVE_COMMAND_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveCommand : public CommandBase
{
private:
	bool shiftUp, shiftDown;
public:
	DriveCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
