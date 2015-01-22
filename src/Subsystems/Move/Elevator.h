#ifndef ELEVATOR
#define ELEVATOR

#include "Commands/Subsystem.h"
#include "WPILib.h"



class Elevator: public Subsystem
{
    public:
        Elevator();
        ~Elevator();

        void driveMotor(double speed);
        void stopMotor();
        enum switches {
            ENDSWITCH,
            READYSWITCHTOP,
            BINSWITCH,
            READYSWITCHBOTTOM
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
        bool changingState = false; // are we going to a state
        Elevator::states getState();
        void toState(Elevator::states desiredPos);
        void nextState();
        void previousState();


        void atState(); //called by the atXswitchmethods when we are at the desired state
        void atEndSwitch();
        void atReadySwitchTop();
        void atReadySwitchBottom();
        void atBinSwitch();
    private:
        Talon *winchMotor;
        Elevator::states state = states::READYBIN; //current state, starts at readybin

        Elevator::switches toTrip; // limit switch that indicates that we have reached our desired stae
        Elevator::states commandedState; // state that we are going to

};

#endif
