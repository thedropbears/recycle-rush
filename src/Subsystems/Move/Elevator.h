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
        int state = states::READYBIN;
        bool changingState = false; // are we going to a state
        int toTrip; // limit switch that indicates that we have reached our desired stae
        int commandedState; // state that we are going to
    public:
        Elevator();
        ~Elevator();
        int getState();
        void driveMotor(double speed);
        void stopMotor();
        void toState(int state);
        enum tripped {
            ENDSWITCH,
            READYSWITCH1,
            READYSWITCH2,
            BINSWITCH
        };
        enum states {
            READYBIN,
            READYTOTE1,
            READYSTACK1,
            READYTOTE2,
            READYTOTE3,
            READYSTACK2,
            READYTOTE4,
            CARRYINGTOTE4
        };

        void atState(); //called by the atswitches when we are at the desired state
        void atEndSwitch();
        void atReadySwitch1();
        void atReadySwitch2();
        void atBinSwitch();
};

#endif
