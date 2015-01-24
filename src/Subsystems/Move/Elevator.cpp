#include "Elevator.h"
#include "../../RobotMap.h"
#include <Commands/Elevator/ChangeState.h>

#include <time.h>

Elevator::Elevator(): Subsystem("Elevator"){
    winchMotor = new Talon(WINCH_TALON_PWM);

    endSwitchTripped = false;
    readySwitchTopTripped = false;
    readySwitchBottomTripped = false;

    endSwitchTrigger = new LimitTrigger(Elevator::switches::ENDSWITCH);
    endSwitchTrigger->WhenActive(new ChangeState(Elevator::switches::ENDSWITCH));

    readySwitchTopTrigger = new LimitTrigger(Elevator::switches::READYSWITCHTOP);
    readySwitchTopTrigger->WhenActive(new ChangeState(Elevator::switches::READYSWITCHTOP));

    readySwitchBottomTrigger = new LimitTrigger(Elevator::switches::READYSWITCHBOTTOM);
    readySwitchBottomTrigger->WhenActive(new ChangeState(Elevator::switches::READYSWITCHBOTTOM));
}

Elevator::~Elevator() {
    delete winchMotor;
}



void Elevator::toState(Elevator::states desiredPos) {
    commandedState = desiredPos;
    // somehow call nextstate/previousstate methods repeatedly
    if(abs((commandedState - state) > 0)) {
        changingState = true;
        if((commandedState - state) > 0) {
            nextState(true);
        } else {
            previousState(true);
        }
    }
    PutDashboard();
}


//called by the various atswitch methods if we have just tripped the correct switch
void Elevator::atState() {
    if(goingToState == commandedState) {
        state = goingToState;
        commandedState = state;
        changingState = false;
        stopMotor();
        toTrip = switches::NOSWITCH;
    } else {
        toState(commandedState);
    }
    PutDashboard();
}

void Elevator::nextState(bool toStateCalled) {
    if(state < states::CARRYINGTOTE4) {
        changingState = true;
        goingToState = static_cast<Elevator::states>(state + 1);
        if(!toStateCalled) {
            commandedState = goingToState;
        }
        driveMotor(WINCH_MOTOR_SPEED);
        toTrip = upSwitches[goingToState - 1];
        SmartDashboard::PutString("Elevator Status: ", "Going to next state");
    }
    PutDashboard();
}

void Elevator::previousState(bool toStateCalled) {
    if(state > states::READYBIN) {
        changingState = true;
        goingToState = static_cast<Elevator::states>(state - 1);
        if(!toStateCalled) {
            commandedState = goingToState;
        }
        driveMotor(-WINCH_MOTOR_SPEED);
        //figure out what limit switch needs to be tripped
        toTrip = downSwitches[goingToState];
        SmartDashboard::PutString("Elevator Status: ", "Going to previous state");
    }
    PutDashboard();
}

void Elevator::PutDashboard() {
    std::string state_string;
    switch(state) {
    case states::READYBIN:
        state_string = "Ready Bin"; break;
    case states::READYTOTE1 :
        state_string = "Ready Tote 1"; break;
    case states::READYSTACK1 :
        state_string = "Ready Stack 1"; break;
    case states::READYTOTE2 :
        state_string = "Ready Tote 2"; break;
    case states::READYTOTE3 :
        state_string = "Ready Tote 3"; break;
    case states::READYSTACK2 :
        state_string = "Ready Stack 2"; break;
    case states::READYTOTE4 :
        state_string = "Ready Tote 4"; break;
    case states::CARRYINGTOTE4 :
        state_string = "Carrying Tote 4"; break;
    }
    SmartDashboard::PutString("Elevator State: ", state_string);
    std::string switch_string;
    switch(toTrip) {
    case switches::ENDSWITCH:
        switch_string = "End Switch"; break;
    case switches::READYSWITCHTOP:
        switch_string = "Top Ready Switch"; break;
    case switches::READYSWITCHBOTTOM:
        switch_string = "Bottom Ready Switch"; break;
    case switches::NOSWITCH:
        switch_string = "N/A"; break;
    }
    SmartDashboard::PutString("To Trip: ", switch_string);
    std::string going_to_string;
    if(goingToState != state) {
        switch(goingToState) {
            case states::READYBIN:
                going_to_string = "Ready Bin"; break;
            case states::READYTOTE1 :
                going_to_string = "Ready Tote 1"; break;
            case states::READYSTACK1 :
                going_to_string = "Ready Stack 1"; break;
            case states::READYTOTE2 :
                going_to_string = "Ready Tote 2"; break;
            case states::READYTOTE3 :
                going_to_string = "Ready Tote 3"; break;
            case states::READYSTACK2 :
                going_to_string = "Ready Stack 2"; break;
            case states::READYTOTE4 :
                going_to_string = "Ready Tote 4"; break;
            case states::CARRYINGTOTE4 :
                going_to_string = "Carrying Tote 4"; break;
        }
    } else {
        going_to_string = "At State";
    }
    SmartDashboard::PutString("To State: ", going_to_string);
    SmartDashboard::PutBoolean("Changing State: ", changingState);
}

void Elevator::driveMotor(double speed) {
    winchMotor->Set(speed);
}

void Elevator::stopMotor() {
    winchMotor->Set(0.0f);
}

void Elevator::atEndSwitch() {
    atState();
    stopMotor();
}

void Elevator::atReadySwitchTop() {
    if(toTrip == Elevator::switches::READYSWITCHTOP) {
        atState();
    }
}

void Elevator::atReadySwitchBottom() {
    if(toTrip == Elevator::switches::READYSWITCHBOTTOM) {
        atState();
    }
}

Elevator::states Elevator::getState() {
    return state;
}

Elevator::switches Elevator::getToTrip() {
    return toTrip;
}
