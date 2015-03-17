
#ifndef AUTONOMOUSELEVATORCOMMAND_H
#define AUTONOMOUSELEVATORCOMMAND_H
#include "../CommandBase.h"

class AutonomousElevatorCommand : public CommandBase
{
private:


public:
	AutonomousElevatorCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

};

#endif
