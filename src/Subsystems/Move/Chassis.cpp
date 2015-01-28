#include "Chassis.h"
#include "../../RobotMap.h"
#include "CommandBase.h"

#include <Commands/Move/OmniDrive.h>
#include <lib-4774/Functions.h>


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

    fieldCentered = true;
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

    if(fieldCentered) {
        float tempVX = vX;
        vX = lib4774::fieldOrient(lib4774::joystick_axis::X, CommandBase::imu->GetYaw(), vX, vY);
        vY = lib4774::fieldOrient(lib4774::joystick_axis::Y, CommandBase::imu->GetYaw(), tempVX, vY);
    }

    SmartDashboard::PutBoolean("Field Oriented: ", fieldCentered);
    SmartDashboard::PutNumber("vX: ", vX);
    SmartDashboard::PutNumber("vY: ", vY);

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
double* Chassis::EncoderDistance() {
    //motors a b d and e
    encoder_distance[0] = motor_a->GetPosition();
    encoder_distance[1] = motor_b->GetPosition();
    encoder_distance[2] = motor_d->GetPosition();
    encoder_distance[3] = motor_e->GetPosition();
    return encoder_distance;
}

double Chassis::ReturnDistance() {
    double Distance = encoder_distance[0] * (WHEEL_CIRCUMFRENCE / ENCODER_COUNTS_PER_REVOLUTION);
    return Distance;
}

void Chassis::ZeroEncoders() {
    motor_a->SetPosition(0.0);
    motor_b->SetPosition(0.0);
    motor_d->SetPosition(0.0);
    motor_e->SetPosition(0.0);
}
