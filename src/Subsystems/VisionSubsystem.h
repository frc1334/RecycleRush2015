#ifndef VISION_SUBSYSTEM_H
#define VISION_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

class VisionSubsystem: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	ColorImage *Image = new RGBImage("/testImage.jpg");
	//BinaryImage *thresholdImage = Image->TresholdHSV(treshold);
	AxisCamera *camera;


public:
	VisionSubsystem();
	void InitDefaultCommand();
	void particalAnalysis();
	void initCamera();
	void Reset();
	struct Scores;
	struct TargetReport;
};

#endif
