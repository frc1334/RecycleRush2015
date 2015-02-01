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
	ColorImage Image1;

public:
	VisionSubsystem();
	void InitDefaultCommand();
	void Reset();
	struct TargetReport;
	struct Scores;
	void Start();

	void WriteMaxFPS(int maxFPS);
	void Stop();
	bool isHot();
};

#endif
