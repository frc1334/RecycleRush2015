#include "LiftSubsystem.h"
#include "../RobotMap.h"


//Subsystem to move the elevator

LiftSubsystem::LiftSubsystem() : PIDSubsystem("E2levatorSubsystem",p,i,d), left(ELEVATOR_LEFT), right(ELEVATOR_RIGHT)
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
	cout << beltEncoderL->GetRaw();
	return beltEncoderL->GetRaw();
}

void LiftSubsystem::UsePIDOutput(double output)
{
	//cout << output << endl;
	if(beltEncoderL->GetRate() > beltEncoderR->GetRate())
	{
		left.Set(output*.8);
	}
	if(beltEncoderR->GetRate() > beltEncoderL->GetRate())
	{
		right.Set(-output *0.8);
	}
	right.Set(-output);

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
