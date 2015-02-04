#include "VisionSubsystem.h"
#include "../RobotMap.h"

VisionSubsystem::VisionSubsystem() :
		Subsystem("VisionSubsystem"), Camera(CAMERA1),Image()
{

}

struct Scores
{
	double rectangularity;
	double aspectRatioVertical;
	double aspectRatioHorizontal;
};
struct TargetReport
{
	int verticalIndex;
	int horizontalIndex;
	bool Hot;
	double totalScore;
	double leftScore;
	double rightScore;
	double tapeWidthScore;
	double verticalScore;
};
void VisionSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


void initCamera()
{
	Camsera.GetImage(Image);

}

void particalAnalysis()
{

}

void VisionSubsystem::Reset()
{

}
