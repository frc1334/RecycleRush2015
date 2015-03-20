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


// Joysticks
const int JOYSTICK_DRIVE = 0;
const int JOYSTICK_OPERATOR = 1;
// Motors
const int LEFT1 = 0;
const int LEFT2 = 1;
const int RIGHT1 = 2;
const int RIGHT2 = 3;
const int ELEVATOR_LEFT = 4;
const int ELEVATOR_RIGHT = 5;
const int INTAKE_MOTOR_LEFT = 6;
const int INTAKE_MOTOR_RIGHT = 7;
const int WINCH = 8;
// Solenoids
const int INTAKE_SOLENOID = 0;
// Digital Input
const int ELEVATOR_ENCODER_L = 0;
const int ELEVATOR_ENCODER_L_B = 1;
const int ELEVATOR_ENCODER_R = 2;
const int ELEVATOR_ENCODER_R_B = 3;
const int ELEVATOR_LIMITSWITCH_L = 4;
const int ELEVATOR_LIMITSWITCH_R = 5;
// Encoders
const int ENCODER_BELT_LEFT = 0;
const int ENCODER_BELT_RIGHT = 1;

static const double ELEVATOR_BOTTOM = 0.0;
static const double ELEVATOR_ONE_TOTE = 0.0;
static const double ELEVATOR_DRIVING = 0.0;
static const double ELEVATOR_PLACING = 0.0;
// LAST EDITED - 25/02/2015

#endif
