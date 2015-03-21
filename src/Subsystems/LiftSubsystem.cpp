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

void LiftSubsystem::ZeroLimitSwitch()
{
	cout << "L Limit Switch:" << limitSwitchL->Get() << endl;
	cout << "R Limit Switch:" << limitSwitchR->Get() << endl;
	// If the right encoder is 0 and the limit switch is not pressed - means that the elevator is not zeroed, so zero it
	if (beltEncoderR->GetDistance() == 0 && limitSwitchR->Get())
	{
		cout << " Right Going Down" << beltEncoderR->GetDistance() << endl;
		cout << "R Limit Switch:" << limitSwitchR->Get() << endl;
		while (limitSwitchR->Get())
		{
			right.Set(1);
			if (!limitSwitchR->Get())
			{
				right.Set(0);
				beltEncoderR->Reset();
				setpointR = 50;
				break;
			}
		}

	}
	// If the left encoder is 0 and the limit switch is not pressed - means that the elevator is not zeroed, so zero it
	if (beltEncoderL->GetDistance() == 0 && limitSwitchL->Get())
	{
		cout << " Left Going Down" << beltEncoderL->GetDistance() << endl;
		cout << "L Limit Switch:" << limitSwitchL->Get() << endl;
		while (limitSwitchL->Get())
		{
			left.Set(-1);
			if (!limitSwitchL->Get())
			{
				left.Set(0);
				beltEncoderL->Reset();
				setpointL = 50;
				break;
			}

		}
	}

	/*if (!limitSwitchL->Get() && !limitSwitchR->Get())
	 {
	 setpoint = 10;
	 }*/

}

void LiftSubsystem::LimitSwitchSafety(float speed)
{
	if (!limitSwitchL->Get())
	{
		beltEncoderL->Reset();
		if (speed < 0)
		{
			left.Set(speed);
		}
		if (speed > 0 || speed == 0)
		{
			left.Set(0);
		}

	}
	if (!limitSwitchR->Get())
	{
		beltEncoderR->Reset();
		if (speed < 0)
		{
			right.Set(0);
		}
		if (speed > 0 || speed == 0)
		{

			right.Set(-speed);
		}
	}
	if (!limitSwitchR->Get() && !limitSwitchL->Get())
	{
		right.Set(-1);
		right.Set(1);
		setpointR = 50;
		setpointL = 50;
		beltEncoderR->Reset();
		beltEncoderL->Reset();
	}
}

void LiftSubsystem::Lift(float speed, float x)
{
	ZeroLimitSwitch();
	cout << "SetpointL " << setpointL << endl;
	cout << "SetpointR " << setpointR << endl;

	cout << "Encoder R: " << beltEncoderR->GetDistance() << endl;
	cout << "Encoder L: " << beltEncoderL->GetDistance() << endl;
	float min = 50;
	float max = 2500;
	int increment = -10;
	if (speed >= 0.25f)
	{
		speed = 1;
	}
	else if (speed <= -0.25f)
	{
		speed = -1;
	}

	if (x <= 0.5 && x >= -0.5)
	{
		if (speed == -1 || speed == 1 || speed == 0)
		{
			setpointL += (speed * increment);
			setpointR += (speed * increment);

			if (setpointL >= max)
			{
				setpointL = max;
			}
			if (setpointL <=min)
			{
				setpointL =min;
			}
			if (setpointL < 0)
			{
				setpointL = 0;
			}

			if (setpointR >= max)
			{
				setpointR = max;
			}
			if (setpointR <=min)
			{
				setpointR =min;
			}
			if (setpointR < 0)
			{
				setpointR = 0;
			}

		}
	}
		if (beltEncoderR->GetDistance() < setpointR)
		{
			right.Set(-0.5f);
		}
		if (beltEncoderL->GetDistance() < setpointL)
		{
			left.Set(0.5f);
		}

		if (beltEncoderR->GetDistance() > setpointR)
		{
			right.Set(0.5f);
		}
		if (beltEncoderL->GetDistance() > setpointL)
		{
			left.Set(-0.6f);
		}

	if (beltEncoderL->GetDistance() >= (setpointL - 4)
			&& beltEncoderL->GetDistance() <= (setpointL + 4))
	{
		//setpointL = beltEncoderL->GetDistance();
		left.Set(0);
	}
	if (beltEncoderR->GetDistance() >= (setpointR - 4)
			&& beltEncoderR->GetDistance() <= (setpointR + 4))
	{
		//setpointR = beltEncoderR->GetDistance();

		right.Set(0);
	}

	// DO NOT COMMENT OUT (Instructions unclear uncommented, comment)
	LimitSwitchSafety(speed);
	// EVER

}

void LiftSubsystem::Lift(float speed)
{
	float leftD = 0.9f;
	float leftU = 0.95f;
	float rightD = 0.9f;
	float rightU = 0.92f;
	if (speed < 0)
	{
		left.Set(-speed * leftU);
		right.Set(speed * rightU);
	}
	if (speed > 0)
	{
		left.Set(-speed * leftD);
		right.Set(speed * rightD);
	}
	if (speed == 0)
	{
		left.Set(0);
		right.Set(0);
	}

	// DO NOT COMMENT OUT (Instructions unclear uncommented, comment)
	if (!limitSwitchL->Get())
	{
		if (speed < 0)
		{
			left.Set(speed);
		}
		if (speed > 0 || speed == 0)
		{
			left.Set(0);
		}
	}
	if (!limitSwitchR->Get())
	{

		if (speed < 0)
		{
			right.Set(0);
		}
		if (speed > 0 || speed == 0)
		{

			right.Set(-speed);
		}
	}
	if (!limitSwitchR->Get() && !limitSwitchL->Get())
	{
		right.Set(-1);
		right.Set(1);

	}
	// EVER

}

void LiftSubsystem::InitDefaultCommand()
{
}

void LiftSubsystem::Reset()
{
}

