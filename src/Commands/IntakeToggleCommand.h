#ifndef INTAKETOGGLE_COMMAND_H
#define INTAKETOGGLE_COMMAND_H

#include "../CommandBase.h"
#include "WPILib.h"

class IntakeToggleCommand: public CommandBase
{
private:

public:
	IntakeToggleCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
