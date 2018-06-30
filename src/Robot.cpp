#include "RobotServer.h"
#include "MotorController.h"
#include <core/TaskManager.h>

MotorController a (27, 22);
MotorController b (23, 24);

RobotServer server;
Robust::TaskManager manager (60);

void handle(int) {
	a.SetThrottle(server.Throttle1);
	b.SetThrottle(server.Throttle2);
}

int main() {
    manager.AddTask(&handle);
    server.Join();
}
