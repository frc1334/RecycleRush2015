#ifndef SRC_COMMANDS_AUTONOMOUSINTAKECOMMAND_H_
#define SRC_COMMANDS_AUTONOMOUSINTAKECOMMAND_H_
#include "../CommandBase.h"

class AutonomousIntakeCommand : public CommandBase
{
private:
	Timer delay;
	double seconds;
	float x,y;

public:
	AutonomousIntakeCommand(double seconds, float x, float y);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};


#endif
