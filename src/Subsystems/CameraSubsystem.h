
#ifndef CAMERASUBSYSTEM_H
#define CAMERASUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"
#include <opencv2/opencv.hpp>

using namespace cv;

class CameraSubsystem : public Subsystem
{
	Image *frame;
	AxisCamera *camera;
public:
	CameraSubsystem();
};

#endif
