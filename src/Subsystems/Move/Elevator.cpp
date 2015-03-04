#include "Elevator.h"

#include <RobotMap.h>
#include <Commands/Elevator/ChangeState.h>


Elevator::Elevator(): Subsystem("Elevator"){
    winchMotor = new CANTalon(WINCH_TALON_CAN_ID);

    endSwitchTripped = false;
    readySwitchTopTripped = false;
    readySwitchBottomTripped = false;

    endSwitchTrigger = new LimitTrigger(END_CHANNEL);
    endSwitchTrigger->WhenActive(new ChangeState(Elevator::switches::ENDSWITCH, this));

    readySwitchTopTrigger = new IrTrigger(READY_CHANNEL_TOP);
    readySwitchTopTrigger->WhenActive(new ChangeState(Elevator::switches::READYSWITCHTOP, this));

    readySwitchBottomTrigger = new IrTrigger(READY_CHANNEL_BOTTOM);
    readySwitchBottomTrigger->WhenActive(new ChangeState(Elevator::switches::READYSWITCHBOTTOM, this));

    binSwitchTrigger = new LimitTrigger(BIN_SWITCH_CHANNEL);
    binSwitchTrigger->WhenActive(new ChangeState(Elevator::switches::BINSWITCH, this));

    winchMotor->SetFeedbackDevice(CANTalon::AnalogEncoder);

    for(int i = 0; i < 4; i++) {
        switchLastTrippedPos[i] = getEncoder();
    }
    toTripIndex = 0;
    sequence = {switches::NOSWITCH};
}

Elevator::~Elevator() {
    delete winchMotor;
}



void Elevator::toState(Elevator::states desiredPos) {
    commandedState = desiredPos;
    if(abs((commandedState - state) > 0)) {
        if((commandedState - state) > 0) {
            nextState(true);
        } else {
            previousState(true);
        }
    }
    PutDashboard();
}

void Elevator::switchSequence(states start_state, states end_state) {
    // set sequence to a list of limit switches that need to be tripped to get to end_state from start_state
    toTripIndex = 0;
    sequence.clear(); // zero all of the elements
    //sequence.reserve(1); // make the first element pushed to the vector take the element at the zero index
    if(start_state < end_state) {
        for(int i = start_state; i < end_state; i++) {
            //if(sequence.size() == 1 && sequence[])
            sequence.push_back(upSwitches[i][0]);
            if(upSwitches[i][1] != switches::NOSWITCH)
                sequence.push_back(upSwitches[i][1]);
        }
    } else if (start_state > end_state) {
        for(int i = start_state - 1; i > end_state - 1; i--) {
            sequence.push_back(downSwitches[i][0]);
            if(upSwitches[i][1] != switches::NOSWITCH)
                sequence.push_back(downSwitches[i][1]);
        }
    } else {
        sequence[0] = switches::NOSWITCH;
    }
}


//called by the various atswitch methods if we have just tripped the correct switch
void Elevator::atState() {
    state = commandedState;
    changingState = false;
    stopMotor();
    PutDashboard();
}

void Elevator::nextState(bool toStateCalled) {
    if(state < states::CARRYINGTOTE4 && (commandedState >= state)) {
        changingState = true;
        if(!toStateCalled) {
            if(commandedState < states::CARRYINGTOTE4) {
                commandedState = static_cast<Elevator::states>(commandedState + 1);
            }
        }
        driveMotor(WINCH_MOTOR_SPEED);
        switchSequence(state, commandedState);
    }else if ((commandedState > state) && changingState) {
        if(commandedState == state-1) {
            commandedState = state;
            if(toTripIndex == 0) {
                changingState = true;
                sequence.resize(1);
                sequence[0] = upSwitches[state][0];
            } else {
                sequence[0] = sequence[1];
                sequence.resize(2);
                sequence[1] = upSwitches[state][0];
            }
            toTripIndex = 0;
            driveMotor(-WINCH_MOTOR_SPEED);
        }
    }
    PutDashboard();
}

void Elevator::previousState(bool toStateCalled) {
    if(state > states::READYBIN && (commandedState <= state)) {
        changingState = true;
        if(!toStateCalled) {
            if(commandedState > states::READYBIN) {
                commandedState = static_cast<Elevator::states>(commandedState - 1);
             }
        }
        driveMotor(-WINCH_MOTOR_SPEED);
        switchSequence(state, commandedState);
    } else if ((commandedState > state) && changingState) {
        if(commandedState == state+1) {
            commandedState = state;
            if(toTripIndex == 0) {
                changingState = true;
                sequence.resize(1);
                sequence[0] = downSwitches[state-1][0];
            } else {
                sequence[0] = sequence[1];
                sequence.resize(2);
                sequence[1] = downSwitches[state - 1][0];
            }
            toTripIndex = 0;
            driveMotor(-WINCH_MOTOR_SPEED);
        }
    }
    PutDashboard();
}



void Elevator::driveMotor(double speed) {
    speed = -speed;
    if(speed < 0 && endSwitchTrigger->Get()){
        return;
    } else if (speed > 0 && binSwitchTrigger->Get()) {
        return;
    }
    winchMotor->Set(speed);
}

void Elevator::stopMotor() {
    winchMotor->Set(0.0f);
}

float Elevator::getSpeed() {
    return -winchMotor->Get();
}

void Elevator::atEndSwitch() {
    /*if(abs(switchLastTrippedPos[3] - getEncoder()) > LIMIT_SWITCH_IGNORE) {
        state = states::CARRYINGTOTE4;
        goingToState = state;
        commandedState = state;
        changingState = false;
        if(winchMotor->Get() < 0) {
            stopMotor();
        }
        toTrip = switches::NOSWITCH;
    }*/
    state = states::CARRYINGTOTE4;
    commandedState = state;
    changingState = false;
    if(winchMotor->Get() < 0) {
        stopMotor();
    }
}

void Elevator::atReadySwitchTop() {
    if(sequence[toTripIndex] == Elevator::switches::READYSWITCHTOP
            //&& abs(switchLastTrippedPos[2] - getEncoder()) > LIMIT_SWITCH_IGNORE
            ) {
        if(toTripIndex == sequence.size()-1) {
            atState();
        } else{
            toTripIndex++;
        }
    }
}

void Elevator::atReadySwitchBottom() {
    if(sequence[toTripIndex] == Elevator::switches::READYSWITCHBOTTOM
            //&& abs(switchLastTrippedPos[1] - getEncoder()) > LIMIT_SWITCH_IGNORE
            ) {
        if(toTripIndex == sequence.size()-1) {
            SmartDashboard::PutString("ATstate", "");
            atState();
        } else{
            toTripIndex++;
        }
    }
}

void Elevator::atBinSwitch() {
    /*if(abs(switchLastTrippedPos[0] - getEncoder()) > LIMIT_SWITCH_IGNORE) {
        state = states::READYBIN;
        goingToState = state;
        commandedState = state;
        changingState = false;
        if(winchMotor->Get() > 0) {
            stopMotor();
        }
        stopMotor();
        toTrip = switches::NOSWITCH;
    }*/
    state = states::READYBIN;
    commandedState = state;
    changingState = false;
    if(winchMotor->Get() > 0) {
        stopMotor();
    }
}

Elevator::states Elevator::getState() {
    return state;
}

Elevator::states Elevator::getCommandedState() {
    return commandedState;
}

double Elevator::getEncoder() {
    //return winchMotor->GetPosition();
    //return winchMotor->GetAnalogInRaw();
    return winchMotor->GetPosition()/ENCODER_COUNTS_PER_REVOLUTION*ENCODER_TO_SPOOL*ELEVATOR_MAX_SPOOL_SIZE;
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
    switch(sequence[toTripIndex]) {
    case switches::ENDSWITCH:
        switch_string = "End Switch"; break;
    case switches::READYSWITCHTOP:
        switch_string = "Top Ready Switch"; break;
    case switches::READYSWITCHBOTTOM:
        switch_string = "Bottom Ready Switch"; break;
    case switches::BINSWITCH:
        switch_string = "Bin Switch"; break;
    case switches::NOSWITCH:
        switch_string = "N/A"; break;
    }
    SmartDashboard::PutString("To Trip: ", switch_string);
    std::string commanded_string;
    if(commandedState != state) {
        switch(commandedState) {
            case states::READYBIN:
                commanded_string = "Ready Bin"; break;
            case states::READYTOTE1 :
                commanded_string = "Ready Tote 1"; break;
            case states::READYSTACK1 :
                commanded_string = "Ready Stack 1"; break;
            case states::READYTOTE2 :
                commanded_string = "Ready Tote 2"; break;
            case states::READYTOTE3 :
                commanded_string = "Ready Tote 3"; break;
            case states::READYSTACK2 :
                commanded_string = "Ready Stack 2"; break;
            case states::READYTOTE4 :
                commanded_string = "Ready Tote 4"; break;
            case states::CARRYINGTOTE4 :
                commanded_string = "Carrying Tote 4"; break;
        }
    } else {
        commanded_string = "Current";
    }
    SmartDashboard::PutString("Commanded State: ", commanded_string);
    SmartDashboard::PutBoolean("Changing State: ", changingState);
    SmartDashboard::PutNumber("Bin Switch: ", CommandBase::elevator->binSwitchTrigger->Get());
    SmartDashboard::PutNumber("End Switch: ", CommandBase::elevator->endSwitchTrigger->Get());
    SmartDashboard::PutNumber("Bottom Switch: ", CommandBase::elevator->readySwitchBottomTrigger->GetValue());
    SmartDashboard::PutNumber("Top Switch: ", CommandBase::elevator->readySwitchTopTrigger->GetValue());
    SmartDashboard::PutNumber("To Trip Index: ", toTripIndex);
    SmartDashboard::PutNumber("Sequence Size: ", sequence.size());
}
