#include "ToteIntake.h"
#include <RobotMap.h>

ToteIntake::ToteIntake(): Subsystem("ToteIntake") {
    left_motor = new CANTalon(TOTE_INTAKE_LEFT_ID);
    right_motor = new CANTalon(TOTE_INTATE_RIGHT_ID);
}

void ToteIntake::DriveIn() {
    left_motor->Set(TOTE_INTAKE_SPEED);
    right_motor->Set(-TOTE_INTAKE_SPEED);
}

void ToteIntake::DriveOut() {
    left_motor->Set(-TOTE_INTAKE_SPEED);
    right_motor->Set(TOTE_INTAKE_SPEED);
}

void ToteIntake::Stop() {
    left_motor->Set(0.0);
    right_motor->Set(0.0);
}
