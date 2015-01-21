#include "Elevator.h"
#include "../../RobotMap.h"

#include <time.h>

Elevator::Elevator(): Subsystem("Elevator"){
    winchMotor = new Talon(WINCH_TALON_PWM);
}

Elevator::~Elevator() {
    delete winchMotor;
}



void Elevator::toState(Elevator::states desiredPos) {
    changingState = true;
    commandedState = desiredPos;
    SmartDashboard::PutNumber("To State: ", commandedState);
    SmartDashboard::PutBoolean("Changing State: ", changingState);
    // somehow call nextstate/previousstate methods repeatedly
}

//called by the various atswitch methods if we have just tripped the correct switch
void Elevator::atState() {
    changingState = false;
    winchMotor->Set(0.0f);
    SmartDashboard::PutBoolean("Changing State: ", changingState);
    state = commandedState;
}

void Elevator::nextState() {
    if(state < states::CARRYINGTOTE4) {
        commandedState = static_cast<Elevator::states>(state + 1);
        driveMotor(WINCH_MOTOR_SPEED);
        //figure out what limit switch needs to be tripped
    }
}

void Elevator::previousState() {
    if(state > states::READYBIN) {
        commandedState = static_cast<Elevator::states>(state - 1);
        driveMotor(-WINCH_MOTOR_SPEED);
        //figure out what limit switch needs to be tripped
    }
}

void Elevator::driveMotor(double speed) {
    winchMotor->Set(speed);
}

void Elevator::stopMotor() {
    winchMotor->Set(0.0f);
}

Elevator::states Elevator::getState() {
    return state;
}

void Elevator::atBinSwitch() {
    if(toTrip == Elevator::switches::BINSWITCH) {
        atState();
    }
}

void Elevator::atEndSwitch() {
    if(toTrip == Elevator::switches::ENDSWITCH) {
        atState();
    }
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
