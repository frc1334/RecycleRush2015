#include "LiftSubsystem.h"
#include "../RobotMap.h"


//Subsystem to move the elevator

LiftSubsystem::LiftSubsystem() : PIDSubsystem("LiftSubsystem",p,i,d),
LiftMotorL(ELEVATOR_LEFT), LiftMotorR(ELEVATOR_RIGHT)
{
	LiveWindow *lw = LiveWindow::GetInstance();
	SetAbsoluteTolerance(0.05f);
	GetPIDController()->SetContinuous(false);

	lw->AddActuator("LiftSubsystem", "PIDSubsystem Controller", GetPIDController());

	beltEncoderL = new Encoder(0, 1, false, Encoder::EncodingType::k4X);
	beltEncoderL->SetMaxPeriod(.1);
	beltEncoderL->SetMinRate(10);
	beltEncoderL->SetDistancePerPulse(5);
	beltEncoderL->SetSamplesToAverage(7);
	beltEncoderL->SetPIDSourceParameter(Encoder::PIDSourceParameter::kDistance);

	beltEncoderR = new Encoder(2, 3, true, Encoder::EncodingType::k4X);
	beltEncoderR->SetMaxPeriod(.1);
	beltEncoderR->SetMinRate(10);
	beltEncoderR->SetDistancePerPulse(5);
	beltEncoderR->SetSamplesToAverage(7);
	beltEncoderR->SetPIDSourceParameter(Encoder::PIDSourceParameter::kDistance);
}
double LiftSubsystem::ReturnPIDInput()
{
	return beltEncoderL->PIDGet();
}

void LiftSubsystem::UsePIDOutput(double output)
{
	LiftMotorL.Set(output);
	LiftMotorR.Set(-output);
}

void LiftSubsystem::InitDefaultCommand()
{
}

void LiftSubsystem::Reset()
{
}
