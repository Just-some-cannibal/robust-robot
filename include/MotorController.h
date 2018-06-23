#pragma once

#include <fstream>
#include <string>

#include <core/IMotorController.h>


// An implementation of IMotorController for raspberry pi that uses pi-blaster
class MotorController : Robust::IMotorController {
private:
	const std::string FileName = "/dev/pi-blaster";
	double Throttle;
	std::fstream File;
	int Pin1, Pin2;
public:
	// Takes the two pins of the gpio that will be used to interface with the hbridge
	MotorController(int, int); 

	double GetThrottle(); // S
	void SetThrottle(double);
};