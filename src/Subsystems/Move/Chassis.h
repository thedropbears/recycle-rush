#ifndef CHASSIS_H
#define CHASSIS_H

#include "WPILib.h"

class Chassis: public Subsystem {
private:
    CANTalon* motor_a;
    CANTalon* motor_b;
    CANTalon* motor_c;
    CANTalon* motor_d;
    CANTalon* motor_e;
    CANTalon* motor_f;
public:
    Chassis();
    ~Chassis();
    void Drive(double vX, double vY, double vZ, double Throttle, double k);
    void InitDefaultCommand();
};

#endif
