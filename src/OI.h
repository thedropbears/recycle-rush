#ifndef OI_H
#define OI_H

#include <WPILib.h>

#include <RobotMap.h>

//WORD OF WARNING: do not include commands here (interrupttrigger is not a command) as it will break the linker.

class OI
{
private:
    Joystick* JoyDrv;
    Joystick* GameDrv;

    //joystick buttons
    Button* gyroResetButton;
    Button* fieldOrientButton;
    Button* elevatorUpButton;
    Button* elevatorDownButton;
    Button* nextElevatorPositionButton;
    Button* previousElevatorPositionButton;
    Button* stackButton;
    Button* togglePIDButton;
    Button* strobeButton;
    Button* stopElevatorButton;
    Button* intakeToteButton;
    Button* outputToteButton;

    //gamepad buttons
    Button* gamepadStackButton;
    Button* gamepadStopElevatorButton;
    Button* gamepadElevatorUpButton;
    Button* gamepadElevatorDownButton;
    Button* gamepadRaiseElevatorOverrideButton;
    Button* gamepadLowerElevatorOverrideButton;


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
