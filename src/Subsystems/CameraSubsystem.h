
#ifndef CAMERASUBSYSTEM_H
#define CAMERASUBSYSTEM_H

class CameraSubsystem
{
	IMAQdxSession session;
	Image *frame;
	IMAQdxError imaqError;
	AxisCamera *camera;
public:
	CameraSubsystem();
};

#endif
