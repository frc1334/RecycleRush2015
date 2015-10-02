#ifndef INTAKE_COMMAND_H
#define INTAKE_COMMAND_H

#include "../CommandBase.h"
#include "WPILib.h"

class IntakeCommand : public CommandBase
{
private:

public:
	IntakeCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
