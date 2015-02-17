#ifndef ELEVATOR
#define ELEVATOR

#include <Triggers/IrTrigger.h>
#include <Triggers/LimitTrigger.h>

#define ELEVATOR_MAX_SPOOL_SIZE 15.7 //cm
#define ENCODER_TO_SPOOL 0.5 // how
#define LIMIT_SWITCH_IGNORE 10.0 // cm, the distance after a limit switch has been tripped for which
// we ignore readings from it due to current jumping to air at high frequency

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
            READYSWITCHBOTTOM,
            BINSWITCH, // the switch at the very bottom of the elevator
            NOSWITCH
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
        Elevator::switches upSwitches[7] = {switches::READYSWITCHBOTTOM,
                switches::READYSWITCHTOP, switches::READYSWITCHBOTTOM,
                switches::READYSWITCHBOTTOM, switches::READYSWITCHTOP,
                switches::READYSWITCHBOTTOM, switches::ENDSWITCH};
        Elevator::switches downSwitches[7] = {switches::READYSWITCHBOTTOM,
                switches::READYSWITCHTOP, switches::READYSWITCHBOTTOM,
                switches::READYSWITCHBOTTOM, switches::READYSWITCHTOP,
                switches::READYSWITCHBOTTOM, switches::BINSWITCH};
        bool changingState = false; // are we going to a state
        Elevator::states getState();
        Elevator::switches getToTrip();
        void toState(Elevator::states desiredPos);
        void nextState(bool toStateCalled = false);
        void previousState(bool toStateCalled = false);


        void atState(); //called by the atXswitchmethods when we are at the desired state
        void atEndSwitch();
        void atReadySwitchTop();
        void atReadySwitchBottom();
        void atBinSwitch();

        void PutDashboard();

        bool endSwitchTripped;
        bool readySwitchTopTripped;
        bool readySwitchBottomTripped;
        bool binSwitchTripped;
        double getEncoder();
        LimitTrigger* endSwitchTrigger;
        IrTrigger* readySwitchBottomTrigger;
        IrTrigger* readySwitchTopTrigger;
        LimitTrigger* binSwitchTrigger;
    private:
        CANTalon *winchMotor;
        Elevator::states state = states::READYBIN; //current state, starts at readybin

        Elevator::switches toTrip; // limit switch that indicates that we have reached our desired stae
        Elevator::states commandedState = states::READYBIN; // state that we are going to
        Elevator::states goingToState = states::READYBIN;

        double switchLastTrippedPos[4]; // bin,bottom, top, end
};

#endif
