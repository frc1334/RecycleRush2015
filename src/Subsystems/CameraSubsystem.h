
#ifndef CAMERASUBSYSTEM_H
#define CAMERASUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"


class CameraSubsystem : public Subsystem
{
	ColorImage *frame;
	AxisCamera *camera;
	BinaryImage *tresholdImage;
	BinaryImage *convexHullImage = tresholdImage->ConvexHull(false);
	BinaryImage *filteredImage = convexHullImage->ParticleFilter;
	ParticleAnalysisReport *reports = filteredImage->GetParticleAnalysisReport(1);

public:
	CameraSubsystem();

};

#endif
