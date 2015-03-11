#include "LiftSubsystem.h"
#include "../RobotMap.h"


//Subsystem to move the elevator

LiftSubsystem::LiftSubsystem() : PIDSubsystem("E2levatorSubsystem",p,i,d), left(ELEVATOR_LEFT), right(ELEVATOR_RIGHT)
{
	limitSwitchL = new DigitalInput(ELEVATOR_LIMITSWITCH_L);
	limitSwitchR = new DigitalInput(ELEVATOR_LIMITSWITCH_R);

	LiveWindow *lw = LiveWindow::GetInstance();
	SetAbsoluteTolerance(0.01f);
	GetPIDController()->SetContinuous(true);

	lw->AddActuator("LiftSubsystem", "PIDSubsystem Controller", GetPIDController());

	beltEncoderL = new Encoder(ELEVATOR_ENCODER_L, ELEVATOR_ENCODER_L_B, false, Encoder::EncodingType::k4X);
	beltEncoderL->Reset();
	beltEncoderL->SetMaxPeriod(.05);
	beltEncoderL->SetMinRate(10);
	beltEncoderL->SetDistancePerPulse(1);
	beltEncoderL->SetSamplesToAverage(7);
	beltEncoderL->SetPIDSourceParameter(Encoder::PIDSourceParameter::kDistance);

	beltEncoderR = new Encoder(ELEVATOR_ENCODER_R, ELEVATOR_ENCODER_R_B, true, Encoder::EncodingType::k4X);
	beltEncoderR->Reset();
	beltEncoderR->SetMaxPeriod(.05);
	beltEncoderR->SetMinRate(10);
	beltEncoderR->SetDistancePerPulse(1);
	beltEncoderR->SetSamplesToAverage(7);
	beltEncoderR->SetPIDSourceParameter(Encoder::PIDSourceParameter::kDistance);
}
double LiftSubsystem::ReturnPIDInput()
{
	return (beltEncoderL->PIDGet() + beltEncoderR->PIDGet())/2;
}

void LiftSubsystem::UsePIDOutput(double output)
{
	cout << "Left Limit Switch: " << limitSwitchL->Get() << endl;
	cout << "Right Limit Switch: " << limitSwitchR->Get() << endl;
	cout << output << endl;
	double leftOut;
	double rightOut;
	/*while((limitSwitchL->Get() && limitSwitchR->Get())
			|| (!limitSwitchL->Get() && !limitSwitchR->Get()))
	{
		if(limitSwitchL->Get() && limitSwitchR->Get())
		{
			beltEncoderL->Reset();
			beltEncoderR->Reset();
			//SetSetpoint(15);
			cout << "Setpoint 15" << endl;;
			//break;
		}

	}*/

	/*if((limitSwitchL->Get() && lim8 itSwitchR->Get())
			|| (!limitSwitchL->Get() && !limitSwitchR->Get()))
	{

		left.PIDWrite(output);
		cout << output << endl;
		right.PIDWrite(-output);
	}*/
	double percentage = .5;
	if(beltEncoderL->GetRaw()*output > beltEncoderR->GetRaw()*output)
	{
		leftOut = output*percentage;
		rightOut = -output;
	}
	else
	{
		leftOut = output;
		rightOut = -output*percentage;
	}

	if(output > 0.25)
	{
		if(limitSwitchL->Get())
		{
			beltEncoderL->Reset();
			left.PIDWrite(0);
			if(!limitSwitchR->Get())
				right.Set(rightOut);
			else
			{
				right.Set(0);
				beltEncoderR->Reset();
			}

		}
		else
		{
			left.Set(output);
			if(!limitSwitchR->Get())
				right.Set(leftOut);
			else
			{
				right.Set(0);
				beltEncoderR->Reset();
			}

		}

	}
	else if(output < -0.25)
	{
		right.Set(rightOut);
		left.Set(leftOut);
	}
	else
	{
		right.Set(0);
		left.Set(0);
	}

}

void LiftSubsystem::InitDefaultCommand()
{
}

void LiftSubsystem::Reset()
{
}
