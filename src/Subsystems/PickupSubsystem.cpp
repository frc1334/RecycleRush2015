#include "PickupSubsystem.h"
#include "../RobotMap.h"




PickupSubsystem::PickupSubsystem() :
		Subsystem("PickupSubsystem"), BeltMotorLeft(BELTMOTORLEFT), BeltMotorRight(BELTMOTORRIGHT),WheelSolenoidLeft(WHEELSOLENOIDLEFT), WheelSolenoidRight(WHEELSOLENOIDRIGHT)
{

}

void PickupSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


	// For OI, have a button that when pressed, runs open, and when released, runs close?
void PickupSubsystem::Open(float Speed){
	Speed = 1;
	//We haven't set delays on the pistons and motors
	//Is this necessary?

	if(WheelSolenoidLeft.Get() == false){
	WheelSolenoidLeft.Set(true);
	}
	if(WheelSolenoidRight.Get() == false){
	WheelSolenoidRight.Set(true);
	}

	BeltMotorLeft.Set(Speed);
	BeltMotorRight.Set(Speed * -1);



}

void PickupSubsystem::Close(float Speed){
	Speed = 0;

	if(WheelSolenoidLeft.Get() == true){
		WheelSolenoidLeft.Set(false);
		}
		if(WheelSolenoidRight.Get() == true){
		WheelSolenoidRight.Set(false);
		}

		BeltMotorLeft.Set(Speed);
		BeltMotorRight.Set(Speed);


}

void PickupSubsystem::Reset()
{
}
