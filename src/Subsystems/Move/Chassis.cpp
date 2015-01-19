#include "Chassis.h"
#include "../../RobotMap.h"

#include <Commands/OmniDrive.h>


Chassis::Chassis() :
    Subsystem("Chassis") {
    motor_a = new CANTalon(DRIVE_MOTOR_A_ID);
    motor_b = new CANTalon(DRIVE_MOTOR_B_ID);
    motor_c = new CANTalon(DRIVE_MOTOR_C_ID);
    motor_c->SetControlMode(CANSpeedController::ControlMode::kFollower);
    motor_c->Set(DRIVE_MOTOR_B_ID);
    motor_d = new CANTalon(DRIVE_MOTOR_D_ID);
    motor_e = new CANTalon(DRIVE_MOTOR_E_ID);
    motor_f = new CANTalon(DRIVE_MOTOR_F_ID);
    motor_f->SetControlMode(CANSpeedController::ControlMode::kFollower);
    motor_f->Set(DRIVE_MOTOR_E_ID);

}

Chassis::~Chassis() {
    delete motor_a;
    delete motor_b;
    delete motor_c;
    delete motor_d;
    delete motor_e;
    delete motor_f;

}

void Chassis::Drive(double vX, double vY, double vZ, double Throttle, double k) {
    //Set up variables for each motor
    double mA;
    double mB;
    double mC;
    double mD;

    mA = 0 - vY - k * vZ;
    mB = vX + 0 -vZ;
    mC = 0 + vY - k * vZ;
    mD = -vX +0 -vZ;

    double motorInput [] = {mA, mB, mC, mD};

    double max = 1;

    for (int i = 0; i <= 3; i += 1)
    {
        if (abs(motorInput[i]) > max)
        {
                max = abs(motorInput[i]);
        }
    }

    for (int i =0; i <= 3; i += 1)
    {
        motorInput[i] = motorInput[i]/max;
    }

    for (int i =0; i <= 3; i += 1)
    {
        motorInput[i] = motorInput[i] * Throttle;
    }

    motor_a->Set(motorInput[0]);
    motor_b->Set(motorInput[1]);
    motor_d->Set(motorInput[2]);
    motor_e->Set(motorInput[3]);

}

void Chassis::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    //SetDefaultCommand(new MySpecialCommand());
    SetDefaultCommand(new OmniDrive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

