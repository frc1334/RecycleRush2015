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

	JoystickButton *buttonADrive;
	//JoystickButton *buttonBDrive;
	//JoystickButton *buttonXDrive;
	//JoystickButton *buttonYDrive;

	//JoystickButton *buttonAOperator;
	//JoystickButton *buttonBOperator;
	//JoystickButton *buttonXOperator;
	//JoystickButton *buttonYOperator;


public:
	OI();
	inline float GetDriveSteering() { return -AddDeadZone(Joystick_Drive->GetX(), 0.25f) * 0.5; }
	inline float GetDriveLeftTrigger() { return Joystick_Drive->GetRawAxis(2) *0.5; }
	inline float GetDriveRightTrigger() { return Joystick_Drive->GetRawAxis(3) *0.5; }
	inline float GetDriverIntakeDirection() { return -AddDeadZone(Joystick_Drive->GetRawAxis(4), 0.15f); }
	inline float GetDriverIntakeFocus() { return AddDeadZone(Joystick_Drive->GetRawAxis(5), 0.15f); }

	inline float GetOperatorElevator() { return -AddDeadZone(Joystick_Operator->GetRawAxis(5), 0.15f); }

	inline float AddDeadZone(float original, float deadzone)
	{
		  return ((fabs(original) <= deadzone) ? 0 : original);
	}
};

#endif
