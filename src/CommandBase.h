#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Subsystems/DriveSubsystem.h"
#include "Subsystems/ElevatorSubsystem.h"
#include "Subsystems/LimitswitchSubsystem.h"
#include "Subsystems/PickupSubsystem.h"
#include "Subsystems/VisionSubsystem.h"
#include <string>
#include "Commands/Command.h"
#include "OI.h"
#include "WPILib.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static ElevatorSubsystem *elevatorSubsystem;
	static PickupSubsystem *pickupSubsystem;
	static LimitswitchSubsystem *limitswitchSubsystem;
	static VisionSubsystem *visionSubsystem;
    static OI *oi;
	static DriveSubsystem *driveSubsystem;
};

#endif
