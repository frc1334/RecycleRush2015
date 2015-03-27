#include "Commands/DriveCommand.h"
#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ElevatorCommand.h"
#include "Commands/MagicalMysteryMode.h"
#include "Commands/AutonomousCommandGroup.h"
//#include "Commands/AutonomousShortCommand.h"
#include "Commands/AutonomousFourBin.h"
#include "Commands/IntakeCommand.h"
#include "Commands/WinchCommand.h"
#include "CommandBase.h"
#include <stdio.h>

using namespace std;

class CommandBasedRobot: public IterativeRobot
{
private:
	CommandGroup *autonomousCommand;
	CommandGroup *autonomousFourBin;
	CommandGroup *magicalMysteryMode;
	//CommandGroup *autonomousShortCommand;
	Command *driveCommand;
	Command *winchCommand;
	Command *liftCommand;
	Command *intakeCommand;
	LiveWindow *lw;
	SendableChooser *autoMode;

	virtual void RobotInit()
	{
		CommandBase::init();
		lw =LiveWindow::GetInstance();
		autoMode = new SendableChooser();
		autoMode->AddDefault("Default", new AutonomousCommandGroup());
		//autoMode->AddDefault("Autonomous Siena(short)", new AutonomousShortCommand());
		autoMode->AddObject("Four Bin", new AutonomousFourBin());
		autoMode->AddObject("MagicalMysteryMode(Get Scooby and the Gang)", new MagicalMysteryMode());
		//autonomousCommand = new AutonomousCommandGroup();
		//autonomousFourBin = new AutonomousFourBin();
		SmartDashboard::PutData("Autonomous Mode", autoMode);;
		driveCommand = new DriveCommand();
		winchCommand= new WinchCommand();
		liftCommand = new ElevatorCommand();
		intakeCommand = new IntakeCommand();


	}
	
	virtual void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	virtual void AutonomousInit()
	{
		//autonomousCommand=(Command*)autoMode->GetSelected();
		autonomousCommand->Start();
	}

	virtual void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	virtual void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();

		driveCommand->Start();
		liftCommand->Start();
		intakeCommand->Start();
		winchCommand->Start();

	}

	virtual void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	virtual void TestPeriodic()
	{
		//lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);

