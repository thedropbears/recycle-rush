#ifndef OI_H
#define OI_H

#include "WPILib.h"

#include "RobotMap.h"

//WORD OF WARNING: do not include commands here (interrupttrigger is not a command) as it will break the linker.

#include "lib-4774/commands/InterruptTrigger.h"

class OI
{
private:
    Joystick* JoyDrv;

    Button* gyroResetButton;

public:
	OI();
	Joystick* getJoyDrv();
    double getJoyDrvX();
    double getJoyDrvY();
    double getJoyDrvZ();
    double getJoyDrvThrottle();
    double applyDeadZone(double,double);
};

#endif
