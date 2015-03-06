#include "LiftSubsystem.h"
#include "../RobotMap.h"


//Subsystem to move the elevator

LiftSubsystem::LiftSubsystem() : PIDSubsystem("E2levatorSubsystem",p,i,d), left(ELEVATOR_LEFT), right(ELEVATOR_RIGHT)
{
	LiveWindow *lw = LiveWindow::GetInstance();
	SetAbsoluteTolerance(0.01f);
	GetPIDController()->SetContinuous(true);

	lw->AddActuator("LiftSubsystem", "PIDSubsystem Controller", GetPIDController());

	beltEncoderL = new Encoder(0, 1, false, Encoder::EncodingType::k4X);
	beltEncoderL->SetMaxPeriod(.05);
	beltEncoderL->SetMinRate(10);
	beltEncoderL->SetDistancePerPulse(1);
	beltEncoderL->SetSamplesToAverage(7);
	beltEncoderL->SetPIDSourceParameter(Encoder::PIDSourceParameter::kDistance);

	beltEncoderR = new Encoder(2, 3, true, Encoder::EncodingType::k4X);
	beltEncoderR->SetMaxPeriod(.05);
	beltEncoderR->SetMinRate(10);
	beltEncoderR->SetDistancePerPulse(1);
	beltEncoderR->SetSamplesToAverage(7);
	beltEncoderR->SetPIDSourceParameter(Encoder::PIDSourceParameter::kDistance);
}
double LiftSubsystem::ReturnPIDInput()
{
	return beltEncoderL->PIDGet();
}

void LiftSubsystem::UsePIDOutput(double output)
{
	double midpoint = beltEncoderL->GetRate() + beltEncoderR->GetRate();
	left.Set(output);
	right.Set(-output);
	//if(limitSwitchL->Get())
	//	beltEncoderL->Reset();
	//if(limitSwitchR->Get())
	//	beltEncoderR->Reset();
	// "Perfect" combo
	if(midpoint <= 0.35 || midpoint >= -0.35)
	{
		left.Set(output);
		right.Set(-output);
	}
	// Going Up
	else if(beltEncoderL->GetRate() > -beltEncoderR->GetRate())
	{
		left.Set(output * 0.8);
		right.Set(-output);
	}
	// Going Down
	else if(beltEncoderR->GetRate() > -beltEncoderL->GetRate())
	{
		left.Set(output);
		right.Set(-output * 0.8);
	}

}

void LiftSubsystem::Lift(float speed)
{
	left.Set(speed);
	right.Set(-speed);
}

void LiftSubsystem::InitDefaultCommand()
{
}

void LiftSubsystem::Reset()
{
}
