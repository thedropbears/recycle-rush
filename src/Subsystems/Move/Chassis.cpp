#include "Chassis.h"
#include "../../RobotMap.h"

#include "../../Commands/Drive.h"


Chassis::Chassis() :
        Subsystem("Chassis") {
    motor_a = new Talon(DRIVE_MOTOR_A_PWM);
    motor_b = new Talon(DRIVE_MOTOR_B_PWM);
    motor_c = new Talon(DRIVE_MOTOR_C_PWM);
    motor_d = new Talon(DRIVE_MOTOR_D_PWM);

}

Chassis::~Chassis() {
    delete motor_a;
    delete motor_b;
    delete motor_c;
    delete motor_d;

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

    double array [] = {mA, mB, mC, mD};

    double max = 1;

    for (int i = 0; i <= 3; i += 1)
    {
        if (abs(array[i]) > max)
        {
                max = abs(array[i]);
        }
    }

    for (int i =0; i <= 3; i += 1)
    {
        array[i] = array[i]/max;
    }

    for (int i =0; i <= 3; i += 1)
    {
        array[i] = array[i] * Throttle;
    }


    motor_a->Set(array[0]);
    motor_b->Set(array[1]);
    motor_c->Set(array[2]);
    motor_d->Set(array[3]);

}

void Chassis::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    //SetDefaultCommand(new MySpecialCommand());
    SetDefaultCommand(new Drive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

