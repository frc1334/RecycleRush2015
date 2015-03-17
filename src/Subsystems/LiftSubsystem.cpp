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

	beltEncoderR = new Encoder(ELEVATOR_ENCODER_R, ELEVATOR_ENCODER_R_B, true,
			Encoder::EncodingType::k4X);
	beltEncoderR->SetMaxPeriod(.05);
	beltEncoderR->SetMinRate(10);
	beltEncoderR->SetDistancePerPulse(1);
	beltEncoderR->SetSamplesToAverage(7);
	//beltEncoderR->SetPIDSourceParameter(Encoder::PIDSourceParameter::kDistance);
}

void LiftSubsystem::Lift(float speed)
{

	float max = 1500;
	int increment = -7;

	if (speed == -1 || speed == 1 || speed == 0)
	{
		setpoint += (speed * increment);
		if (setpoint >= max)
		{
			setpoint = max;
		}
		if (setpoint < 0)
		{
			setpoint = 0;
		}

	}

	cout << "Setpoint " << setpoint << endl;
	cout << "Left Encoder " << beltEncoderL->GetDistance() << endl;
	/*
	 bool lzero = false;
	 bool rzero = false;

	 cout << "L Limit Switch:" << limitSwitchL->Get() << endl;
	 cout << "R Limit Switch:" << limitSwitchR->Get() << endl;
	 // If the right encoder is 0 and the limit switch is not pressed - means that the elevator is not zeroed, so zero it
	 if (beltEncoderR->GetDistance() == 0 && limitSwitchR->Get())
	 {
	 cout << " Right Going Down" << beltEncoderR->GetDistance() << endl;
	 cout << "R Limit Switch:" << limitSwitchR->Get() << endl;
	 while (limitSwitchR->Get())
	 {
	 right.Set(0.25f);
	 if (!limitSwitchR->Get())
	 {
	 rzero = true;
	 beltEncoderR->Reset();
	 break;
	 }
	 }
	 if (rzero)
	 {
	 right.Set(0);
	 rzero = false;
	 }

	 }
	 // If the left encoder is 0 and the limit switch is not pressed - means that the elevator is not zeroed, so zero it
	 if (beltEncoderL->GetDistance() == 0 && limitSwitchL->Get())
	 {
	 cout << " Left Going Down" << beltEncoderL->GetDistance() << endl;
	 cout << "L Limit Switch:" << limitSwitchL->Get() << endl;
	 while (limitSwitchL->Get())
	 {
	 left.Set(-0.25f);
	 if (!limitSwitchL->Get())
	 {
	 lzero = true;
	 beltEncoderL->Reset();
	 break;
	 }

	 }
	 if (lzero)
	 {
	 left.Set(0);
	 lzero = false;
	 }
	 }*/

	float diffR = setpoint - beltEncoderR->GetDistance();
	float diffL = setpoint - beltEncoderL->GetDistance();

	if ((beltEncoderR->GetDistance() <= (setpoint + 4) || beltEncoderR->GetDistance() >= (setpoint - 4)) && beltEncoderR->GetDistance() > 0)
	{
		right.Set(-0.25f);
	}
	else if ((beltEncoderL->GetDistance() <= (setpoint + 4) || beltEncoderL->GetDistance() >= (setpoint - 4)) && beltEncoderL->GetDistance() > 0)
	{
		left.Set(0.25f);
	}

	if ((beltEncoderR->GetDistance() <= (setpoint + 4) || beltEncoderR->GetDistance() >= (setpoint - 4)) && beltEncoderR->GetDistance() > 0)
	{
		right.Set(0.25f);
	}
	else if ((beltEncoderL->GetDistance() <= (setpoint + 4) || beltEncoderL->GetDistance() >= (setpoint - 4)) && beltEncoderL->GetDistance() > 0)
	{
		left.Set(-0.25f);
	}

	/*if(beltEncoderL->GetDistance() <= (setpoint + 4) && beltEncoderL->GetDistance() >= (setpoint - 4))
	{
		left.StopMotor();
	}
	if(beltEncoderR->GetDistance() <= (setpoint + 4) && beltEncoderR->GetDistance() >= (setpoint - 4))
	{
		right.StopMotor();
	}*/

	/*
	 *
	 if (setpoint > beltEncoderL->GetDistance())
	 left.Set(diffL * 0.001f);
	 if (setpoint < beltEncoderL->GetDistance())
	 left.Set(-(diffL * 0.001f));
	 if (setpoint > beltEncoderR->GetDistance())
	 right.Set(-(diffR * 0.001f));
	 if (setpoint < beltEncoderR->GetDistance())
	 right.Set(diffR * 0.001f);
	 */
	// DO NOT COMMENT OUT (Instructions unclear uncommented, comment)
	if (!limitSwitchL->Get())
	{
		if (speed < 0)
			left.StopMotor();
		else
		{
			if (setpoint < beltEncoderL->GetDistance())
				left.Set(diffL * 0.001f);
		}
		beltEncoderL->Reset();

	}
	if (!limitSwitchR->Get())
	{
		if (speed < 0)
			right.StopMotor();
		else
		{
			if (setpoint > beltEncoderR->GetDistance())
				right.Set(-(diffR * 0.001f));
		}
		beltEncoderR->Reset();

	}
	// EVER
}

void LiftSubsystem::InitDefaultCommand()
{
}

void LiftSubsystem::Reset()
{
}

