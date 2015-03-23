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

/*void LiftSubsystem::NSLift(float speed)
{
	left.Set(speed);
	right.Set(-speed);

}*/
/*void LiftSubsystem::Lift(float speed)
{
	beltEncoderL->Reset();
	beltEncoderR->Reset();
	float max=2500;
	float min=50;
	setpoint+=speed;
	if(beltEncoderL->Get()<min)
	{
		setpoint=min;
	}
	if(beltEncoderR->Get()<min)
	{
		setpoint=min;
	}
	if(beltEncoderL->Get()>max)
	{
		setpoint=max;
	}
	if(beltEncoderR->Get()>max)
	{
		setpoint=max;
	}

	if(beltEncoderR->Get()<setpoint)
	{
		right.Set(-1);
	}
	if(beltEncoderL->Get()<setpoint)
	{
		left.Set(1);
	}
	if(beltEncoderR->Get()>setpoint)
	{
		right.Set(-1);
	}
	if(beltEncoderL->Get()>setpoint)
	{
		left.Set(1);
	}
	if(beltEncoderR->Get()==setpoint)
	{
		right.StopMotor();
	}
	if(beltEncoderL->Get()==setpoint)
	{
		left.StopMotor();
	}
}*/
void LiftSubsystem::Lift(float speed)
{
	beltEncoderL->Reset();
	beltEncoderR->Reset();
	float basespeedLeft=-(speed*.86);
	float basespeedRight=speed;
	//float ifValue2=speed*.95;
	left.Set(basespeedLeft);
	right.Set(basespeedRight);
	if(limitSwitchL->Get()==0)
	{
		if(speed<0)
		{
			beltEncoderL->Reset();
			left.StopMotor();

		}
	}
	if(limitSwitchR->Get()==0)
	{
		if(speed<0)
		{
			right.StopMotor();
			beltEncoderR->Reset();
		}
	}


	if(speed<0 && beltEncoderL->GetDistance()<beltEncoderR->GetDistance())
	{
		left.Set(basespeedLeft*.25);
	}
	if(speed<0 && beltEncoderL->GetDistance()>beltEncoderR->GetDistance())
		{
			right.Set(basespeedRight*.25);
		}
	if(speed>0 && beltEncoderL->GetDistance()<beltEncoderR->GetDistance())
		{
			right.Set(basespeedRight*.25);
		}
	if(speed>0 && beltEncoderL->GetDistance()>beltEncoderR->GetDistance())
		{
				left.Set(basespeedLeft*.25);
		}
	std::cout<<"BeltEncoderR RAW:"<<beltEncoderL->GetRaw()<<endl;
	std::cout<<"BeltEncoderL RAW: "<<beltEncoderR->GetRaw()<<endl;
	std::cout<<"BeltEncoderR DISTANCE:"<<beltEncoderL->GetDistance()<<endl;
	std::cout<<"BeltEncoderL DISTANCE: "<<beltEncoderR->GetDistance()<<endl;
	std::cout<<"BeltEncoderR:"<<beltEncoderL->Get()<<endl;
	std::cout<<"BeltEncoderL: "<<beltEncoderR->Get()<<endl;
	/*if(beltEncoderL->Get()>beltEncoderR->Get())
	{
		left.Set(ifValue2);
	}*/
}
/*void LiftSubsystem::EZLift(float position)
{
	float max=2500;
	float min=50;
	setpoint+=position*200;
	if(beltEncoderL->Get()<min)
	{
		setpoint=min;
	}
	if(beltEncoderL->Get()>max)
	{
		setpoint=max;
	}

	if(beltEncoderR->Get()<setpoint)
	{
		right.Set(-1);
	}
	if(beltEncoderL->Get()<setpoint)
	{
		left.Set(1);
	}
	if(beltEncoderR->Get()>setpoint)
	{
		right.Set(1);
	}
	if(beltEncoderL->Get()>setpoint)
	{
		left.Set(-1);
	}
	if(beltEncoderR->Get()==setpoint)
	{
		right.StopMotor();
	}
	if(beltEncoderL->Get()==setpoint)
	{
		left.StopMotor();
	}
}
*/
void LiftSubsystem::InitDefaultCommand()
{
}

void LiftSubsystem::Reset()
{
}

