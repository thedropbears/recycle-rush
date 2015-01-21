#include "Elevator.h"
#include "../../RobotMap.h"

#include <time.h>

Elevator::Elevator(): Subsystem("Elevator"){
    binSwitch = new DigitalInput(BIN_CHANNEL);
    readySwitch1 = new DigitalInput(READY_CHANNEL1);
    readySwitch2 = new DigitalInput(READY_CHANNEL2);
    endSwitch = new DigitalInput(END_CHANNEL);

    winchMotor = new Talon(WINCH_TALON_PWM);

    state = 0;
}

Elevator::~Elevator() {
    delete binSwitch;
    delete readySwitch1;
    delete readySwitch2;
    delete endSwitch;
    delete winchMotor;
}

void Elevator::driveMotor(double speed) {
    winchMotor->Set(speed);
}

void Elevator::stopMotor() {
    winchMotor->Set(0.0f);
}

int Elevator::getState() {
    return state;
}

void Elevator::toState(int desiredPos) {
    changingState = true;
    commandedState = desiredPos;
    SmartDashboard::PutNumber("To State: ", commandedState);
    SmartDashboard::PutBoolean("Changing State: ", changingState);
}

void Elevator::atState() {
    changingState = false;
    winchMotor->Set(0.0f);
    SmartDashboard::PutBoolean("Changing State: ", changingState);
    state = commandedState;
}

void Elevator::atBinSwitch() {

}

void Elevator::atEndSwitch() {

}

void Elevator::atReadySwitch1() {

}

void Elevator::atReadySwitch2() {

}
