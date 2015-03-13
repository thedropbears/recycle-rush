#ifndef ELEVATOR
#define ELEVATOR

#include <vector>

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
        float getSpeed();
        enum switches {
            ENDSWITCH,
            READYSWITCHTOP,
            READYSWITCHBOTTOM,
            BINSWITCH, // the switch at the very bottom of the elevator
            NOSWITCH
        };
        enum states {
            READYBIN,     // 0
            // up/downswitches 0
            READYTOTE1,   // 1
            // up/downswitches 1
            READYSTACK1,  // 2
            // up/downswitches 2
            READYTOTE2,   // 3
            // up/downswitches 3
            READYTOTE3,   // 4
            // up/downswitches 4
            READYSTACK2,  // 5
            // up/downswitches 5
            READYTOTE4,   // 6
            // up/downswitches 6
            CARRYINGTOTE4 // 7
        };
        Elevator::switches upSwitches[7][2] = {{switches::READYSWITCHTOP, switches::READYSWITCHBOTTOM},
        {switches::READYSWITCHTOP, switches::NOSWITCH}, {switches::READYSWITCHBOTTOM, switches::NOSWITCH},
        {switches::READYSWITCHTOP, switches::READYSWITCHBOTTOM}, {switches::READYSWITCHTOP, switches::NOSWITCH},
        {switches::READYSWITCHBOTTOM, switches::NOSWITCH}, {switches::ENDSWITCH, switches::NOSWITCH}};
        Elevator::switches downSwitches[7][2] = {{switches::BINSWITCH, switches::NOSWITCH},
        {switches::READYSWITCHBOTTOM, switches::NOSWITCH}, {switches::READYSWITCHTOP, switches::NOSWITCH},
        {switches::READYSWITCHTOP, switches::READYSWITCHBOTTOM}, {switches::READYSWITCHTOP, switches::READYSWITCHBOTTOM},
        {switches::READYSWITCHTOP, switches::NOSWITCH}, {switches::READYSWITCHBOTTOM, switches::NOSWITCH}
        };

        typedef std::vector<switches> switch_vec;

        void switchSequence(states start_state, states end_state);

        switch_vec sequence;

        /*
        Elevator::switches upSwitches[7] = {switches::READYSWITCHBOTTOM,
                switches::READYSWITCHTOP, switches::READYSWITCHBOTTOM,
                switches::READYSWITCHBOTTOM, switches::READYSWITCHTOP,
                switches::READYSWITCHBOTTOM, switches::ENDSWITCH};
        Elevator::switches downSwitches[7] = {switches::READYSWITCHBOTTOM,
                switches::READYSWITCHTOP, switches::READYSWITCHBOTTOM,
                switches::READYSWITCHBOTTOM, switches::READYSWITCHTOP,
                switches::READYSWITCHBOTTOM, switches::BINSWITCH};*/
        bool changingState = false; // are we going to a state
        Elevator::states getState();
        Elevator::states getCommandedState();
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
        void upOverride();
        void downOverride();
        bool overriding = false;
    private:
        CANTalon *winchMotor;
        Elevator::states state = states::READYBIN; //current state, starts at readybin

        Elevator::states commandedState = states::READYBIN; // state that we are going to
        uint toTripIndex;

        double switchLastTrippedPos[4]; // bin,bottom, top, end
};

#endif
