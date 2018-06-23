#pragma once

#include <cmath>
#include <exception>
#include <thread>

#include "core/IMotorController.h"

namespace Robust
{

class Motor
{
  double StallTorque;          // Max torque without slippage
  double LoadlessSpeed;        // Max Speed with no load
  double Load;                 // Current load in newton meters: Does not include gearbox
  double Inertia;              // Inertia of gearbox
  double OpposingForce;        // Opposing torque acting of the motor
  double OpposingFriction;     // Opposing friction torque (c*n*g) Only applies when object is moving
  IMotorController Controller; // The low level interface to the motor
public:
  // The only required parameter is the controller. The rest default to zero if not set
  Motor(IMotorController controller,
        double stallTorque = 0,
        double loadlessSpeed = 0,
        double load = 0,
        double inertia = 0,
        double opposingForce = 0,
        double opposingFriction = 0);

  double GetStallTorque();
  void SetStallTorque(double);

  double GetLoadLessSpeed();
  void SetLoadlessSpeed(double);

  // Value is between -1 and 1
  // Does not throw error and instead uses -1 or 1 if out of bounds
  void SetThrottle(double);
  double GetThrottle();

  // High level function that sets the throttle based on
  // the stall torque, loadless speed and opposing friction
  // Speed is in rads/s
  // Note: If a speed is given that is higher than the max speed, it will throw std::exception
  void SetSpeed(double);
  double GetSpeed();

  // Predicts the absolute maximum speed that can be given with current set up
  double GetMaxSpeed();

  void SetLoad(double);
  double GetLoad();

  void SetInertia(double); // Probably won't (and shouldn't) change
  double GetInertia();

  void SetOpposingForce(double);
  double GetOpposingForce();

  void SetOpposingFriction(double);
  double GetOpposingFriction();
};

} // namespace Robust
