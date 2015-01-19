#ifndef CHASSIS_H
#define CHASSIS_H

#include "WPILib.h"
#include "Talon.h"

class Chassis: public Subsystem {
private:
    TalonSRX* motor_a;
    TalonSRX* motor_b;
    TalonSRX* motor_c;
    TalonSRX* motor_d;
    TalonSRX* motor_e;
    TalonSRX* motor_f;
public:
    Chassis();
    ~Chassis();
    void Drive(double vX, double vY, double vZ, double Throttle, double k);
    void InitDefaultCommand();
};

#endif
