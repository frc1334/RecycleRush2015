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
	AxisCamera Camera1;
public:
	VisionSubsystem();
	void InitDefaultCommand();
	void Reset();

	void Start();
	int GetImage(ColorImage *image);

	void WriteMaxFPS(int maxFPS);
	void Stop();
	bool isHot();
};

#endif
