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

	beltEncoderL = new Encoder(ELEVATOR_ENCODER_L, ELEVATOR_ENCODER_L_B, true,
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
/*
void LiftSubsystem::NSLift(float speed)
{
	//Lift system used to just do it with no encoder values
	left.Set(speed);
	right.Set(-speed);
}*/

void LiftSubsystem::SetPosition(float setpointL, float setpointR)
{

}

void LiftSubsystem::Lift(float speed)
{
	const float P = 0.015f;
	float max = 2500; //the max setpoint
	float min = 0; //the min set point
	setpointR += -speed * 17;
	setpointL += speed * 17;
	//start of max/min checking
	/*if (setpoint < min)
	{
		setpoint = min;
	}*/

	if (setpointR > max)
	{
		setpointR = max;
	}
	if (setpointL > max)
	{
		setpointL = max;
	}
	//end of max/main checking

	//start of checking if you are at setpoint
	if (beltEncoderR->Get() < setpointR)
	{
		right.Set(-fabs(beltEncoderR->Get() - setpointR) * P);
	}
	if (beltEncoderL->Get() < setpointL)
	{
		left.Set(fabs(beltEncoderL->Get() - setpointL) * P);
	}
	if (beltEncoderR->Get() > setpointR)
	{
		right.Set(fabs(beltEncoderR->Get() - setpointR) * P);
	}
	if (beltEncoderL->Get() > setpointL)
	{
		left.Set(-fabs(beltEncoderL->Get() - setpointL) * P);
	}
	if (OI::AddDeadZone(beltEncoderR->Get() - setpointR, 10) == 0)
	{
		right.Set(0);
	}
	if (OI::AddDeadZone(beltEncoderL->Get() - setpointL, 10) == 0)
	{
		left.Set(0);
	}
	//end of checking if you are at setpoint

	//limit switch checking
	if (!limitSwitchL->Get() && left.Get() <= 0) //if the limit switched is pressed and speed is less then 0 then stop motor
	{
		left.Set(0);
		beltEncoderL->Reset();
		setpointL = 0;
	}
	if (!limitSwitchR->Get() && right.Get() <= 0)
	{
		right.Set(0);
		beltEncoderR->Reset();
		setpointR = 0;
	}
	//end of limitswitch checking
	cout << "L:" << beltEncoderL->Get() << endl;
	cout << "R:" << beltEncoderR->Get() << endl;
	cout << "SetpointR:" << setpointR <<  endl;
	cout << "SetpointL:" << setpointL <<  endl;
	cout << "Left Motor" << left.Get() << endl;
	cout << "Right Motor" << right.Get() << endl;
	cout << "Limit L:" << !limitSwitchL->Get() <<  endl;
	cout << "Limit R:" << !limitSwitchR->Get() <<  endl;
}


void LiftSubsystem::InitDefaultCommand()
{
}

void LiftSubsystem::Reset()
{
}

