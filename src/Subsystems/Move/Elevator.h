#ifndef ELEVATOR
#define ELEVATOR

#include "Commands/Subsystem.h"
#include "WPILib.h"



class Elevator: public Subsystem
{
    private:
        DigitalInput *binSwitch;
        DigitalInput *readySwitch1;
        DigitalInput *readySwitch2;
        DigitalInput *endSwitch;

        Talon *winchMotor;
        int state;
        int lastState;
    public:
        Elevator();
        ~Elevator();
        int getState();
        int getLastState();
        void driveMotor(double speed);
        void stopMotor();

        //return 1 when dio goes low
        static int monitorDIO(DigitalInput *to_monitor);
};

#endif
