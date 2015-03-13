#include "Chassis.h"

#include <Commands/Move/OmniDrive.h>
#include <lib-4774/Functions.h>

const double YAW_P = 2.0;
const double YAW_I = 0.08;
const double YAW_D = 0.0;
const double YAW_MOMENTUM_THRESHOLD (lib4774::d2r(10.0)); //deg/s

const double VEL_P = -0.1;
const double VEL_I = -3.0;
const double VEL_D = 0.0;
const double VEL_F = -2.0;
const int IZONE = 0;
const int VEL_CONTROL_PROFILE = 0;
const double RAMPRATE = 0; //volts/sec


Chassis::Chassis() :
    Subsystem("Chassis") {
    motor_a = new CANTalon(DRIVE_MOTOR_A_ID);
    motor_b = new CANTalon(DRIVE_MOTOR_B_ID);
    motor_c = new CANTalon(DRIVE_MOTOR_C_ID);
    motor_d = new CANTalon(DRIVE_MOTOR_D_ID);

    CANTalon *motors[4] = {motor_a, motor_b, motor_c, motor_d};
    for(int i = 0; i < 4; i++) {
        motors[i]->SetControlMode(CANTalon::ControlMode::kSpeed);
        motors[i]->SelectProfileSlot(VEL_CONTROL_PROFILE);
        motors[i]->SetPID(VEL_P, VEL_I, VEL_D, VEL_F);
        motors[i]->SetIzone(IZONE);
        motors[i]->SetCloseLoopRampRate(RAMPRATE);
    }

    pdp = new PowerDistributionPanel();

    correction = new GyroCorrection();
    gyro_pid = new PIDController(YAW_P, YAW_I, YAW_D, CommandBase::imu, correction);
    gyro_pid->SetInputRange(-M_PI, M_PI);
    gyro_pid->SetContinuous(true);
    gyro_pid->SetSetpoint(0.0);
    gyro_pid->Enable();

    fieldCentered = false;
    momentum = false;

}

Chassis::~Chassis() {
    delete motor_a;
    delete motor_b;
    delete motor_c;
    delete motor_d;
}

void Chassis::Drive(double vX, double vY, double vZ, double throttle) {
    //Set up variables for each motor
    double mA;
    double mB;
    double mC;
    double mD;

    if(fieldCentered) {
        //field orient the stuff
    	double result[2] = {0, 0};
        lib4774::fieldOrient(vX, vY, CommandBase::imu->GetYaw(), result);
        vX = result[0];
        vY = result[1];
    }


    if(gyro_pid->IsEnabled()) {
        if(momentum && abs(CommandBase::imu->GetZGyro()) < YAW_MOMENTUM_THRESHOLD) {
            // we can let the PID take control as the momentum is less than the threshold
            momentum = false;
        }
        if (vZ != 0) {
            // we are spinning under command, so dont let pid take control
            momentum = true;
        }

        if (!momentum) {
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
    SmartDashboard::PutBoolean("PID: ", gyro_pid->IsEnabled());
    SmartDashboard::PutNumber("vX: ", vX);
    SmartDashboard::PutNumber("vY: ", vY);
    SmartDashboard::PutNumber("Set Point: ", lib4774::r2d(gyro_pid->GetSetpoint()));

    mA = vX + vY - vZ;
    mB = vX - vY - vZ;
    mC = -vX - vY - vZ;
    mD = -vX + vY - vZ;


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
        motorInput[i] = motorInput[i] * throttle;
        motorInput[i] *= TALON_CLOSED_LOOP_MULTIPLIER;
    }

    motor_a->Set(-motorInput[0]);
    motor_b->Set(-motorInput[1]);
    motor_c->Set(-motorInput[2]);
    motor_d->Set(-motorInput[3]);

    SmartDashboard::PutNumber("Drive Motor A: ", motor_a->Get());
    SmartDashboard::PutNumber("Drive Motor B: ", motor_b->Get());
    SmartDashboard::PutNumber("Drive Motor C: ", motor_c->Get());
    SmartDashboard::PutNumber("Drive Motor D: ", motor_d->Get());

    SmartDashboard::PutNumber("Current Motor A: ", pdp->GetCurrent(DRIVE_MOTOR_A_ID));
    SmartDashboard::PutNumber("Current Motor B: ", pdp->GetCurrent(DRIVE_MOTOR_B_ID));
    SmartDashboard::PutNumber("Current Motor C: ", pdp->GetCurrent(DRIVE_MOTOR_C_ID));
    SmartDashboard::PutNumber("Current Motor D: ", pdp->GetCurrent(DRIVE_MOTOR_D_ID));
}


void Chassis::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    //SetDefaultCommand(new MySpecialCommand());
    SetDefaultCommand(new OmniDrive());
}

void Chassis::EncoderDistance(double* encoder_distance) {
    //motors a b d and e
    encoder_distance[0] = (motor_a->GetPosition()/ENCODER_COUNTS_PER_REVOLUTION)*WHEEL_CIRCUMFERENCE;
    encoder_distance[1] = (motor_b->GetPosition()/ENCODER_COUNTS_PER_REVOLUTION)*WHEEL_CIRCUMFERENCE;
    encoder_distance[2] = -(motor_c->GetPosition()/ENCODER_COUNTS_PER_REVOLUTION)*WHEEL_CIRCUMFERENCE;
    encoder_distance[3] = -(motor_d->GetPosition()/ENCODER_COUNTS_PER_REVOLUTION)*WHEEL_CIRCUMFERENCE;
}

void Chassis::ZeroEncoders() {
    motor_a->SetPosition(0.0);
    motor_b->SetPosition(0.0);
    motor_c->SetPosition(0.0);
    motor_d->SetPosition(0.0);
}

void Chassis::Stop() {
    motor_a->Set(0.0);
    motor_b->Set(0.0);
    motor_c->Set(0.0);
    motor_d->Set(0.0);
}

void Chassis::EnablePID() {
	gyro_pid->Enable();
	SmartDashboard::PutBoolean("PID: ", gyro_pid->IsEnabled());
}

void Chassis::DisablePID() {
	gyro_pid->Disable();
	SmartDashboard::PutBoolean("PID: ", gyro_pid->IsEnabled());
}

bool Chassis::OnTarget() {
	return gyro_pid->OnTarget();
}

bool Chassis::PIDEnabled() {
	return gyro_pid->IsEnabled();
}

void Chassis::SetHeading(double newHeading) {
	double newHead = atan2(sin(newHeading),cos(newHeading)); //wrap to +- PI
    gyro_pid->Reset();
    gyro_pid->SetSetpoint(newHead);
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

void Chassis::PutDashboard() {
    double chassis_encoders[4] = {};
    this->EncoderDistance(chassis_encoders);
    SmartDashboard::PutNumber("Encoder Motor A: ", chassis_encoders[0]);
    SmartDashboard::PutNumber("Encoder Motor B: ", chassis_encoders[1]);
    SmartDashboard::PutNumber("Encoder Motor C: ", chassis_encoders[2]);
    SmartDashboard::PutNumber("Encoder Motor D: ", chassis_encoders[3]);
    SmartDashboard::PutNumber("Vel Motor A: ", motor_a->GetSpeed());
    SmartDashboard::PutNumber("Vel Motor B: ", motor_b->GetSpeed());
    SmartDashboard::PutNumber("Vel Motor C: ", motor_c->GetSpeed());
    SmartDashboard::PutNumber("Vel Motor D: ", motor_d->GetSpeed());
    SmartDashboard::PutData(this);
}
