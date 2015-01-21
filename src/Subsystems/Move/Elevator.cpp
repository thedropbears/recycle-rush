#include "Elevator.h"
#include "../../RobotMap.h"

Elevator::Elevator(): Subsystem("Elevator"){
    binSwitch = new DigitalInput(BIN_CHANNEL);
    readySwitch1 = new DigitalInput(READY_CHANNEL1);
    readySwitch2 = new DigitalInput(READY_CHANNEL2);
    endSwitch = new DigitalInput(END_CHANNEL);

    winchMotor = new Talon(WINCH_TALON_PWM);

    state = 0;
    lastState = 0;
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

int Elevator::getState() {
    return state;
}

int Elevator::getLastState() {
    return lastState;
}
