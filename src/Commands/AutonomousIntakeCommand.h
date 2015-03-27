#ifndef SRC_COMMANDS_AUTONOMOUSINTAKECOMMAND_H_
#define SRC_COMMANDS_AUTONOMOUSINTAKECOMMAND_H_
#include "../CommandBase.h"

class AutonomousIntakeCommand : public CommandBase
{
private:
	Timer delay;
	double seconds;
	float x,y;
	bool open;

public:
	AutonomousIntakeCommand(double seconds, float x, float y, bool open);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};


#endif
