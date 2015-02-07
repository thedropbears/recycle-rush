#ifndef OI_H
#define OI_H

#include <WPILib.h>

#include <RobotMap.h>

//WORD OF WARNING: do not include commands here (interrupttrigger is not a command) as it will break the linker.

class OI
{
private:
    Joystick* JoyDrv;

    Button* gyroResetButton;
    Button* fieldOrientButton;
    Button* elevatorUpButton;
    Button* elevatorDownButton;
    Button* nextElevatorPositionButton;
    Button* previousElevatorPositionButton;
    Button* stackButton;


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
