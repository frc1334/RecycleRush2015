#ifndef WINCH_COMMAND_H
#define WINCH_COMMAND_H

#include "../CommandBase.h"
#include "WPILib.h"

class WinchCommand : public CommandBase
{
private:

public:
	WinchCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
