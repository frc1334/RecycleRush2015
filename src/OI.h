#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "RobotMap.h"
#include <math.h>


class OI
{
private:
	Joystick *Joystick_Drive;
	Joystick *Joystick_Operator;

public:
	OI();
	inline float GetDriveSteering() { return -AddDeadZone(Joystick_Drive->GetX(), 0.25f) * 0.5; }
	inline float GetDriveLeftTrigger() { return Joystick_Drive->GetRawAxis(2) *0.5; }
	inline float GetDriveRightTrigger() { return Joystick_Drive->GetRawAxis(3) *0.5; }
	inline float GetDriverIntakeDirection() { return AddDeadZone(Joystick_Drive->GetRawAxis(4), 0.15f); }
	inline float GetDriverIntakeSpeed() { return -AddDeadZone(Joystick_Drive->GetRawAxis(5), 0.15f); }
	inline bool GetDriverIntakeToggle() { return Joystick_Drive->GetRawButton(5); }

	inline float GetOperatorElevator() { return AddDeadZone(Joystick_Operator->GetRawAxis(5), 0.20f); }
	inline float GetOperatorElevatorX() { return AddDeadZone(Joystick_Operator->GetRawAxis(1), 0.20f); }
	inline bool GetOperatorEZElevatorRB() { return Joystick_Operator->GetRawButton(6); }
	inline bool GetOperatorEZElevatorLB() { return (!Joystick_Operator->GetRawButton(5)); }
	inline bool GetOperatorOneTote() { return Joystick_Operator->GetRawButton(1); }
	inline bool GetOperatorMoveTotes() { return Joystick_Operator->GetRawButton(2); }
	inline bool GetOperatorWinch(){ return Joystick_Operator->GetRawButton(4);}

	inline static float AddDeadZone(float original, float deadzone)
	{
		  return ((fabs(original) <= deadzone) ? 0 : original);
	}
};

#endif
