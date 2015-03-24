#include "LiftSubsystem.h"
#include "../RobotMap.h"
#include "../OI.h"

//Subsystem to move the elevator

LiftSubsystem::LiftSubsystem() :
		Subsystem("ElevatorSubsystem"), left(ELEVATOR_LEFT), right(
				ELEVATOR_RIGHT)
{
	limitSwitchL = new DigitalInput(ELEVATOR_LIMITSWITCH_L);
	limitSwitchR = new DigitalInput(ELEVATOR_LIMITSWITCH_R);

	//SetAbsoluteTolerance(0.01f);
	//GetPIDController()->SetContinuous(true);

	/*lw->AddActuator("ElevatorSubsystem", "PIDSubsystem Controller",
	 GetPIDController());*/

	beltEncoderL = new Encoder(ELEVATOR_ENCODER_L, ELEVATOR_ENCODER_L_B, false,
			Encoder::EncodingType::k4X);
	beltEncoderL->SetMaxPeriod(.05);
	beltEncoderL->SetMinRate(10);
	beltEncoderL->SetDistancePerPulse(1);
	beltEncoderL->SetSamplesToAverage(7);
	//beltEncoderL->SetPIDSourceParameter(Encoder::PIDSourceParameter::kDistance);

	beltEncoderR = new Encoder(ELEVATOR_ENCODER_R, ELEVATOR_ENCODER_R_B, false,
			Encoder::EncodingType::k4X);
	beltEncoderR->SetMaxPeriod(.05);
	beltEncoderR->SetMinRate(10);
	beltEncoderR->SetDistancePerPulse(1);
	beltEncoderR->SetSamplesToAverage(7);
	//beltEncoderR->SetPIDSourceParameter(Encoder::PIDSourceParameter::kDistance);
}

void LiftSubsystem::NSLift(float speed)
{
	//Lift system used to just do it with no encoder values
	left.Set(speed);
	right.Set(-speed);

}
void LiftSubsystem::Lift(float speed)
{
	float max = 2500; //the max setpoint
	float min = 50; //the min set point
	setpoint += speed;
	//start of max/min checking
	if (beltEncoderL->Get() < min)
	{
		setpoint = min;
	}
	if (beltEncoderL->Get() < min)
	{
		setpoint = min;
	}
	if (beltEncoderL->Get() > max)
	{
		setpoint = max;
	}
	if (beltEncoderR->Get() > max)
	{
		setpoint = max;
	}
	//end of max/main checking

	//start of checking if you are at setpoint
	if (beltEncoderR->Get() < setpoint)
	{
		right.Set(-1);
	}
	if (beltEncoderL->Get() < setpoint)
	{
		left.Set(1);
	}
	if (beltEncoderR->Get() > setpoint)
	{
		right.Set(1);
	}
	if (beltEncoderL->Get() > setpoint)
	{
		left.Set(-1);
	}
	if (beltEncoderR->Get() == setpoint)
	{
		right.StopMotor();
	}
	if (beltEncoderL->Get() == setpoint)
	{
		left.StopMotor();
	}
	//end of checking if you are at setpoint

	//limit switch checking
	if (limitSwitchL->Get() == 0 && speed < 0) //if the limit switched is pressed and speed is less then 0 then stop motor
	{
		left.StopMotor();
	}
	if (limitSwitchR->Get() == 0 && speed < 0)
	{
		right.StopMotor();
	}
	//end of limitswitch checking
}
void LiftSubsystem::EZLift(float position)
{
	//when pressed setpoint is increased by 200 or -200 or 1 tote level
	float max = 2500;
	float min = 50;
	setpoint += position * 200;
	//start of max/min checking
	if (beltEncoderL->Get() < min)
	{
		setpoint = min;
	}
	if (beltEncoderL->Get() < min)
	{
		setpoint = min;
	}
	if (beltEncoderL->Get() > max)
	{
		setpoint = max;
	}
	if (beltEncoderR->Get() > max)
	{
		setpoint = max;
	}
	//end of max/main checking

	//start of checking if you are at setpoint
	if (beltEncoderR->Get() < setpoint)
	{
		right.Set(-1);
	}
	if (beltEncoderL->Get() < setpoint)
	{
		left.Set(1);
	}
	if (beltEncoderR->Get() > setpoint)
	{
		right.Set(1);
	}
	if (beltEncoderL->Get() > setpoint)
	{
		left.Set(-1);
	}
	if (beltEncoderR->Get() == setpoint)
	{
		right.StopMotor();
	}
	if (beltEncoderL->Get() == setpoint)
	{
		left.StopMotor();
	}
}

void LiftSubsystem::InitDefaultCommand()
{
}

void LiftSubsystem::Reset()
{
}

