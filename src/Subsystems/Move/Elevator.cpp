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

void Elevator::stopMotor() {
    if(state > 0) {
        if(winchMotor->Get() > 0) {
            state += 1;
        } else {
            state -= 1;
        }
    } else {
        state = 0;
    }
    winchMotor->Set(0);
}

int Elevator::getState() {
    return state;
}

int Elevator::getLastState() {
    return lastState;
}

int Elevator::monitorDIO(DigitalInput *to_monitor) {
    time_t start_time, timer;
    time(&start_time);
    for (int i = 1; i > 0;)
    {
        time(&timer);
        if (!to_monitor->Get())
        {
            return 1;
        } else if(difftime(timer, start_time) > ELEVATOR_DIO_TIMEOUT) {
            return -1;
        }
    }
}
