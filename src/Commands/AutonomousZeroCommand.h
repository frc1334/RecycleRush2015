#ifndef AUTONOMOUSZEROCOMMAND_H
#define AUTONOMOUSZEROCOMMAND_H
#include "../CommandBase.h"

class AutonomousZeroCommand : public CommandBase
{
private:
	Timer* timer;
public:
	AutonomousZeroCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

};

#endif
