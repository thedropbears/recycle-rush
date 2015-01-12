#ifndef OI_H
#define OI_H

#include "WPILib.h"

#include "lib-4774/commands/InterruptTrigger.h"


class OI
{
private:
    Joystick* joyDrv;
    InterruptTrigger* trigger;

public:
	OI();
	Joystick *getJoyDrv();
	double getJoyDrvX();
	double getJoyDrvY();
	double getJoyDrvZ();
	double getJoyDrvThrottle();
	double applyDeadZone(double input, double deadZone);
};

#endif
