#include "OI.h"
#include "RobotMap.h"


OI::OI()
{
	// Process operator interface input here.
	Joystick_Drive = new Joystick(0);
	Joystick_Operator = new Joystick(1);

}
