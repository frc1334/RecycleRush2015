#include "LiftSubsystem.h"
#include "../RobotMap.h"


//Subsystem to move the elevator

LiftSubsystem::LiftSubsystem() : PIDSubsystem("E2levatorSubsystem",p,i,d), left(ELEVATOR_LEFT), right(ELEVATOR_RIGHT)
{
	limitSwitchL = new DigitalInput(4);
	limitSwitchR = new DigitalInput(5);

	LiveWindow *lw = LiveWindow::GetInstance();
	SetAbsoluteTolerance(0.01f);
	GetPIDController()->SetContinuous(true);

	lw->AddActuator("LiftSubsystem", "PIDSubsystem Controller", GetPIDController());

	beltEncoderL = new Encoder(0, 1, false, Encoder::EncodingType::k4X);
	beltEncoderL->SetMaxPeriod(.05);
	beltEncoderL->SetMinRate(10);
	beltEncoderL->SetDistancePerPulse(1);
	beltEncoderL->SetSamplesToAverage(7);
	beltEncoderL->SetPIDSourceParameter(Encoder::PIDSourceParameter::kRate);

	beltEncoderR = new Encoder(2, 3, true, Encoder::EncodingType::k4X);
	beltEncoderR->SetMaxPeriod(.05);
	beltEncoderR->SetMinRate(10);
	beltEncoderR->SetDistancePerPulse(1);
	beltEncoderR->SetSamplesToAverage(7);
	beltEncoderR->SetPIDSourceParameter(Encoder::PIDSourceParameter::kRate);
}
double LiftSubsystem::ReturnPIDInput()
{
	double midpoint = beltEncoderL->GetRate() - beltEncoderR->GetRate();
	return midpoint;
}

void LiftSubsystem::UsePIDOutput(double output)
{
	left.PIDWrite(output);
	right.PIDWrite(-output);

	if(limitSwitchL->Get())
	{
		beltEncoderL->Reset();
		left.PIDWrite(0);
	}
	if(limitSwitchR->Get())
	{
		beltEncoderR->Reset();
		right.PIDWrite(0);
	}
}

void LiftSubsystem::InitDefaultCommand()
{
}

void LiftSubsystem::Reset()
{
}
