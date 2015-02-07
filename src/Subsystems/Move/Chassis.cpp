#include "Chassis.h"
#include "../../RobotMap.h"
#include "CommandBase.h"

#include <Commands/Move/OmniDrive.h>
#include <lib-4774/Functions.h>

#define YAW_P 3.0
#define YAW_I 0.0
#define YAW_D 0.0
#define YAW_MOMENTUM_THRESHOLD (lib4774::d2r(10.0)) //deg/s

Chassis::Chassis() :
    Subsystem("Chassis") {
    motor_a = new CANTalon(DRIVE_MOTOR_A_ID);
    motor_b = new CANTalon(DRIVE_MOTOR_B_ID);
    motor_b->SetControlMode(CANSpeedController::ControlMode::kFollower);
    motor_b->Set(DRIVE_MOTOR_C_ID);
    motor_c = new CANTalon(DRIVE_MOTOR_C_ID);
    motor_d = new CANTalon(DRIVE_MOTOR_D_ID);
    motor_e = new CANTalon(DRIVE_MOTOR_E_ID);
    motor_f = new CANTalon(DRIVE_MOTOR_F_ID);
    motor_f->SetControlMode(CANSpeedController::ControlMode::kFollower);
    motor_f->Set(DRIVE_MOTOR_E_ID);

    pdp = new PowerDistributionPanel();

    correction = new GyroCorrection();
    gyro_pid = new PIDController(YAW_P, YAW_I, YAW_D, CommandBase::imu, correction);
    gyro_pid->SetInputRange(-M_PI, M_PI);
    gyro_pid->SetContinuous(true);
    gyro_pid->SetSetpoint(0.0);
    gyro_pid->Enable();

    fieldCentered = true;
    momentum = false;
}

Chassis::~Chassis() {
    delete motor_a;
    delete motor_b;
    delete motor_c;
    delete motor_d;
    delete motor_e;
    delete motor_f;

}

void Chassis::Drive(double vX, double vY, double vZ, double throttle) {
    //Set up variables for each motor
    double mA;
    double mC;
    double mD;
    double mE;

    if(fieldCentered) {
        //field orient the stuff
    	double result[2] = {0, 0};
        lib4774::fieldOrient(vX, vY, CommandBase::imu->GetYaw(), result);
        vX = result[0];
        vY = result[1];

        if(momentum && abs(CommandBase::imu->GetZGyro()) < YAW_MOMENTUM_THRESHOLD) {
            // we can let the PID take control as the momentum is less than the threshold
            momentum = false;
        }
        if (vZ != 0) {
            // we are spinning under command, so dont let pid take control
            momentum = true;
        }

        if (!momentum && gyro_pid->IsEnabled()) {
            vZ = correction->correction;
        } else {
            double SetHeading = CommandBase::imu->GetYaw();
            gyro_pid->Reset();
            gyro_pid->SetSetpoint(SetHeading);
            gyro_pid->Enable();
            correction->correction = 0;
        }

    }

    SmartDashboard::PutNumber("Yaw Rate: ", CommandBase::imu->GetZGyro());
    SmartDashboard::PutBoolean("Field Oriented: ", fieldCentered);
    SmartDashboard::PutNumber("vX: ", vX);
    SmartDashboard::PutNumber("vY: ", vY);
    SmartDashboard::PutNumber("Set Point: ", lib4774::r2d(gyro_pid->GetSetpoint()));

    mA = 0 - vY - Strafe_Motor_Ratio * vZ;
    mC = vX + 0 -vZ;
    mD = 0 + vY - Strafe_Motor_Ratio * vZ;
    mE = -vX +0 -vZ;

    double motorInput [] = {mA, mC, mD, mE};

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
        motorInput[i] = motorInput[i] * throttle;
    }

    motor_a->Set(motorInput[0]);
    motor_c->Set(-motorInput[1]);
    motor_d->Set(motorInput[2]);
    motor_e->Set(-motorInput[3]);

    SmartDashboard::PutNumber("Drive Motor A: ", motor_a->Get());
    SmartDashboard::PutNumber("Drive Motor B: ", motor_b->Get());
    SmartDashboard::PutNumber("Drive Motor C: ", motor_c->Get());
    SmartDashboard::PutNumber("Drive Motor D: ", motor_d->Get());
    SmartDashboard::PutNumber("Drive Motor E: ", motor_e->Get());
    SmartDashboard::PutNumber("Drive Motor F: ", motor_f->Get());

    SmartDashboard::PutNumber("Current Motor A: ", pdp->GetCurrent(DRIVE_MOTOR_A_ID));
    SmartDashboard::PutNumber("Current Motor B: ", pdp->GetCurrent(DRIVE_MOTOR_B_ID));
    SmartDashboard::PutNumber("Current Motor C: ", pdp->GetCurrent(DRIVE_MOTOR_C_ID));
    SmartDashboard::PutNumber("Current Motor D: ", pdp->GetCurrent(DRIVE_MOTOR_D_ID));
    SmartDashboard::PutNumber("Current Motor E: ", pdp->GetCurrent(DRIVE_MOTOR_E_ID));
    SmartDashboard::PutNumber("Current Motor F: ", pdp->GetCurrent(DRIVE_MOTOR_F_ID));
}


void Chassis::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    //SetDefaultCommand(new MySpecialCommand());
    SetDefaultCommand(new OmniDrive());
}

double* Chassis::EncoderDistance() {
    //motors a b d and e
    encoder_distance[0] = motor_a->GetPosition()*(WHEEL_CIRCUMFERENCE / ENCODER_COUNTS_PER_REVOLUTION);
    encoder_distance[1] = motor_b->GetPosition()*(WHEEL_CIRCUMFERENCE / ENCODER_COUNTS_PER_REVOLUTION);
    encoder_distance[2] = motor_d->GetPosition()*(WHEEL_CIRCUMFERENCE / ENCODER_COUNTS_PER_REVOLUTION);
    encoder_distance[3] = motor_e->GetPosition()*(WHEEL_CIRCUMFERENCE / ENCODER_COUNTS_PER_REVOLUTION);
    return encoder_distance;
}

void Chassis::ZeroEncoders() {
    motor_a->SetPosition(0.0);
    motor_b->SetPosition(0.0);
    motor_d->SetPosition(0.0);
    motor_e->SetPosition(0.0);
}

void Chassis::Stop() {
    motor_a->Set(0.0);
    motor_b->Set(0.0);
    motor_d->Set(0.0);
    motor_e->Set(0.0);
}

void Chassis::SetHeading(double newHeading) {
    gyro_pid->Reset();
    gyro_pid->SetSetpoint(newHeading);
    gyro_pid->Enable();
    SmartDashboard::PutNumber("Set Point: ", lib4774::r2d(gyro_pid->GetSetpoint()));
}

void Chassis::HeadingChange(double change) {
    gyro_pid->Reset();
    double newHead = CommandBase::imu->GetYaw()+change;
    newHead = atan2(sin(newHead),cos(newHead)); //wrap to +- PI
    gyro_pid->SetSetpoint(newHead);
    gyro_pid->Enable();
    SmartDashboard::PutNumber("Set Point: ", lib4774::r2d(gyro_pid->GetSetpoint()));
}
