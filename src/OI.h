#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "RobotMap.h"
class OI
{
private:
	Joystick Joystick_Drive;
	Joystick Joystick_Operator;
public:
	OI();
	inline float GetDriveSteering() { return -AddDeadZone(Joystick_Drive.GetX(), 0.15f); }
	inline float GetDriveThrottle() { return Joystick_Drive.GetZ(); }

	inline float AddDeadZone(float original, float deadzone)
	{
		  return ((fabs(original) <= deadzone) ? 0 : original);
	}
};

#endif
