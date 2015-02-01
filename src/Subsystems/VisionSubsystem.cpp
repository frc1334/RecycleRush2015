#include "VisionSubsystem.h"
#include "../RobotMap.h"

VisionSubsystem::VisionSubsystem() :
		Subsystem("VisionSubsystem"), Camera1(CAMERA1)
{

}

void VisionSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
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

struct Scores
{
	double rectangularity;
	double aspectRatioVertical;
	double aspectRatioHorizontal;
};
void Start()
{
	void WriteResolution(int GetResolution());
	void WriteMaxFPS(24);
	int GetImage(ColorImage *image1);

}
void Stop()
{



}
bool isHot()
{

	return isHot();
}
void VisionSubsystem::Reset()
{


}
