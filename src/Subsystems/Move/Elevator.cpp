#include "Elevator.h"
#include "../../RobotMap.h"

Elevator::Elevator() {
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

void Elevator::driveMotor(int direction) {
    if (direction >= 0) {
        winchMotor->Set(WINCH_MOTOR_SPEED);
    } else {
        winchMotor->Set(-WINCH_MOTOR_SPEED);
    }
}

void Elevator::goToState(int goTo) {

}

int Elevator::getState() {
    return state;
}

int Elevator::getLastState() {
    return lastState;
}
