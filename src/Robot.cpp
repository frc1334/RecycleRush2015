#include "Commands/DriveCommand.h"
#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ElevatorCommand.h"
#include "Commands/MagicalMysteryMode.h"
#include "Commands/AutonomousCommandGroup.h"
#include "Commands/AutonomousFourBin.h"
#include "Commands/IntakeCommand.h"
#include "Commands/WinchCommand.h"
#include "CommandBase.h"
#include <stdio.h>

using namespace std;

<<<<<<< HEAD
class CommandBasedRobot: public IterativeRobot
=======
class Robot : public IterativeRobot
>>>>>>> origin/master
{
private:
	CommandGroup *autonomousCommand;
	CommandGroup *autonomousFourBin;
	CommandGroup *magicalMysteryMode;
	Command *driveCommand;
	Command *winchCommand;
	Command *liftCommand;
	Command *intakeCommand;
	LiveWindow *lw;
	SendableChooser *autoMode;

	virtual void RobotInit()
	{
		CommandBase::init();

		autoMode = new SendableChooser();
		autoMode->AddDefault("Default", new AutonomousCommandGroup());
		autoMode->AddObject("Four Bin", new AutonomousFourBin());
		autoMode->AddObject("MagicalMysteryMode(Get Scooby and the Gang)", new MagicalMysteryMode());
		autonomousCommand = new AutonomousCommandGroup();
		//autonomousFourBin = new AutonomousFourBin();
		SmartDashboard::PutData("Autonomous Mode", autoMode);;
		driveCommand = new DriveCommand();
		winchCommand= new WinchCommand();
		liftCommand = new ElevatorCommand();
		intakeCommand = new IntakeCommand();
<<<<<<< HEAD
		lw =LiveWindow::GetInstance();

	}
	
	virtual void DisabledPeriodic()
=======

	}

	void DisabledPeriodic()
>>>>>>> origin/master
	{
		Scheduler::GetInstance()->Run();
	}

	virtual void AutonomousInit()
	{
<<<<<<< HEAD
			autonomousCommand= (CommandGroup*)autoMode->GetSelected();
=======
>>>>>>> origin/master
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

