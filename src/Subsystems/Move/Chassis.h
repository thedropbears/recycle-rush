#ifndef CHASSIS_H
#define CHASSIS_H

#include "WPILib.h"
#include "Talon.h"

class Chassis: public Subsystem {
private:
    Talon* motor_a;
    Talon* motor_b;
    Talon* motor_c;
    Talon* motor_d;
public:
    Chassis();
    ~Chassis();
    void Drive(double vX, double vY, double vZ, double Throttle, double k);
    void InitDefaultCommand();
};

#endif
