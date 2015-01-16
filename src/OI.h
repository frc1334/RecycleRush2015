#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "RobotMap.h"
#include <math.h>

class OI
{
private:
	Joystick Joystick_Drive;
	Joystick Joystick_Operator;

public:
	OI();
	inline float GetDriveSteering() { return -AddDeadZone(Joystick_Drive.GetX(), 0.15f); }
	inline float GetDriveLeftTrigger() { return Joystick_Drive.GetRawAxis(2); }
	inline float GetDriveRightTrigger() { return Joystick_Drive.GetRawAxis(3); }


	inline float AddDeadZone(float original, float deadzone)
	{
		//Joystick_Drive.get
		  return ((fabs(original) <= deadzone) ? 0 : original);
	}
};

#endif
