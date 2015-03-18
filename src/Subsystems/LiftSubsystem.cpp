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

void LiftSubsystem::ZeroLimitSwitch()
{
	cout << "L Limit Switch:" << limitSwitchL->Get() << endl;
	cout << "R Limit Switch:" << limitSwitchR->Get() << endl;

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
				left.Set(0);
				beltEncoderL->Reset();
				break;
			}

		}
	}
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
				right.Set(0);
				beltEncoderR->Reset();
				break;
			}
		}

	}
	if (!limitSwitchL->Get() && !limitSwitchR->Get())
	{
		setpoint = 10;
	}

}

void LiftSubsystem::Lift(float speed, float x)
{
	ZeroLimitSwitch();

	float max = 1500;
	int increment = -4;
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
	}
	cout << "Setpoint " << setpoint << endl;
	cout << "Left Encoder " << beltEncoderL->GetDistance() << endl;
	cout << "Right Encoder " << beltEncoderR->GetDistance() << endl;

	if (beltEncoderR->GetDistance() < setpoint)
	{
		right.Set(-0.5);
	}
	if (beltEncoderL->GetDistance() < setpoint)
	{
		left.Set(0.5);
	}

	if (beltEncoderR->GetDistance() > setpoint)
	{
		right.Set(0.5);
	}
	if (beltEncoderL->GetDistance() > setpoint)
	{
		left.Set(-0.5);
	}

	if (beltEncoderL->GetDistance() >= (setpoint - 4)
			&& beltEncoderL->GetDistance() <= (setpoint + 4))
	{
		left.Set(0);
	}
	if (beltEncoderR->GetDistance() >= (setpoint - 4)
			&& beltEncoderR->GetDistance() <= (setpoint + 4))
	{
		right.Set(0);
	}

	// DO NOT COMMENT OUT (Instructions unclear uncommented, comment)
	if (!limitSwitchL->Get())
	{
		beltEncoderL->Reset();
		if (speed < 0)
		{
			left.Set(0);
		}
		else
		{
			left.Set(speed);
		}

	}
	if (!limitSwitchR->Get())
	{
		beltEncoderR->Reset();
		if (speed < 0)
		{
			right.Set(0);
		}
		else
		{
			right.Set(-speed);
		}
	}
	if (!limitSwitchR->Get() && !limitSwitchL->Get())
	{
		setpoint = 10;
		beltEncoderR->Reset();
		beltEncoderL->Reset();
	}
	// EVER
}

void LiftSubsystem::InitDefaultCommand()
{
}

void LiftSubsystem::Reset()
{
}

