#include "LimitswitchSubsystem.h"
#include "../RobotMap.h"

LimitswitchSubsystem::LimitswitchSubsystem() :
		Subsystem("LimitSwitchSubsystem"),Tier1(TIER1),Tier2(TIER2),Tier3(TIER3),
		Tier4(TIER4),Tier5(TIER5),Tier6(TIER6),Tier7(TIER7)
{

}

void LimitswitchSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void LimitswitchSubsystem::Reset()
{
}
