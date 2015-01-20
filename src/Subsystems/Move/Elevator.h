#ifndef ELEVATOR
#define ELEVATOR

#include "Commands/Subsystem.h"
#include "WPILib.h"

#define BIN_CHANNEL 1
#define READY_CHANNEL1 2
#define READY_CHANNEL2 3
#define END_CHANNEL 4

#define WINCH_MOTOR_SPEED 0.2

class Elevator: public Subsystem
{
    private:
        DigitalInput *binSwitch;
        DigitalInput *readySwitch1;
        DigitalInput *readySwitch2;
        DigitalInput *endSwitch;

        Talon *winchMotor;

        void driveMotor(int direction);

        int state;
        int lastState;
    public:
        Elevator();
        ~Elevator();
        int getState();
        int getLastState();
        void goToState(int goTo);

};

#endif
