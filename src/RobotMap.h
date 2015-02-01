#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

const int JOYSTICK_DRIVE = 0;
const int JOYSTICK_OPERATOR = 1;

const int LEFT1 = 1;
const int LEFT2 = 2;
const int RIGHT1 = 3;
const int RIGHT2 = 4;

const int CAMERA1 = 0;

const int SHIFTSOLENOID = 1;

const int ELEVATOR = 5;

const int TIER1 = 0;
const int TIER2 = 0;
const int TIER3 = 0;
const int TIER4 = 0;
const int TIER5 = 0;
const int TIER6 = 0;
const int TIER7 = 0;

#endif
