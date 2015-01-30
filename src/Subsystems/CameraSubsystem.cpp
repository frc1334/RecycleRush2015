/*
 * CameraSubsystem.cpp
 *
 *  Created on: Jan 30, 2015
 *      Author: p
 */

#include "CameraSubsystem.h"

CameraSubsystem::CameraSubsystem() : Subsystem("CameraSubsystem")
{
	frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
	camera = new AxisCamera("10.13.34.10");
	camera->GetImage(frame);

	imaqDrawShapeOnImage(frame, frame, { 10, 10, 100, 100 }, DrawMode::IMAQ_DRAW_VALUE, ShapeMode::IMAQ_SHAPE_OVAL, 0.0f);
	CameraServer::GetInstance()->SetImage(frame);
}
