#include "LiftSubsystem.h"
#include "../RobotMap.h"


//Subsystem to move the elevator

LiftSubsystem::LiftSubsystem() : PIDSubsystem("ElevatorSubsystem",p,i,d), left(ELEVATOR_LEFT), right(ELEVATOR_RIGHT)
{
	limitSwitchL = new DigitalInput(ELEVATOR_LIMITSWITCH_L);
	limitSwitchR = new DigitalInput(ELEVATOR_LIMITSWITCH_R);

	LiveWindow *lw = LiveWindow::GetInstance();
	SetAbsoluteTolerance(0.01f);
	GetPIDController()->SetContinuous(true);

	lw->AddActuator("ElevatorSubsystem", "PIDSubsystem Controller", GetPIDController());

	beltEncoderL = new Encoder(ELEVATOR_ENCODER_L, ELEVATOR_ENCODER_L_B, false, Encoder::EncodingType::k4X);
	beltEncoderL->SetMaxPeriod(.05);
	beltEncoderL->SetMinRate(10);
	beltEncoderL->SetDistancePerPulse(1);
	beltEncoderL->SetSamplesToAverage(7);
	beltEncoderL->SetPIDSourceParameter(Encoder::PIDSourceParameter::kDistance);

	beltEncoderR = new Encoder(ELEVATOR_ENCODER_R, ELEVATOR_ENCODER_R_B, true, Encoder::EncodingType::k4X);
	beltEncoderR->SetMaxPeriod(.05);
	beltEncoderR->SetMinRate(10);
	beltEncoderR->SetDistancePerPulse(1);
	beltEncoderR->SetSamplesToAverage(7);
	beltEncoderR->SetPIDSourceParameter(Encoder::PIDSourceParameter::kDistance);
}
double LiftSubsystem::ReturnPIDInput()
{
	return beltEncoderL->Get() - beltEncoderR->Get();
}


void LiftSubsystem::UsePIDOutput(double output)
{
	cout << "Left Encoder: " << beltEncoderL->Get() << endl;
	cout << "Right Encoder: " << beltEncoderR->Get() << endl;
	if(output < 0.25 || output > 0.25)
			{
				left.PIDWrite(output);
				right.PIDWrite(-output);
			}
			else
			{
				left.StopMotor();
				right.StopMotor();
			}
	if(limitSwitchL->Get() && limitSwitchR->Get())
	{

	}
	else if(!limitSwitchL->Get() && !limitSwitchR->Get())
	{
		left.PIDWrite(output);
		right.PIDWrite(-output);
	}
	else if(limitSwitchL->Get() && !limitSwitchR->Get())
	{
		right.PIDWrite(-output);
		left.StopMotor();
		beltEncoderR->Reset();
	}
	else if(!limitSwitchL->Get() && limitSwitchR->Get())

	{
		left.PIDWrite(output);
		right.StopMotor();
		beltEncoderL->Reset();


	}
}


void LiftSubsystem::InitDefaultCommand()
{
}

void LiftSubsystem::Reset()
{
}
