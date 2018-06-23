#include "MotorController.h"

MotorController::MotorController(int pin1, int pin2) : Pin1(pin1),
 													   Pin2(pin2)
{
}

void MotorController::SetThrottle (double throttle)
{
	if (throttle == Throttle) return;
	Throttle = (throttle > 1)? 1:
			   ((throttle < -1)? -1 : throttle);
	
	double val1 = (throttle > 0)? Throttle: 0;
	double val2 = (throttle > 0)? 0: -Throttle;

	File.open(FileName, std::ios::out | std::ios::trunc);
	File << Pin1 << "=" << val1 << " " << Pin2 << "=" << "val2" << std::endl;
	File.close();
}

double MotorController::GetThrottle()
{
	return Throttle;
}