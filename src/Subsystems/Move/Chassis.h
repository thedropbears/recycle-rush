#ifndef CHASSIS_H
#define CHASSIS_H

#include "WPILib.h"
#define WHEEL_CIRCUMFRENCE 10 //cm
#define ENCODER_COUNTS_PER_REVOLUTION 250 //counts per revolution

class Chassis: public Subsystem {
private:
    CANTalon* motor_a;
    CANTalon* motor_b;
    CANTalon* motor_c;
    CANTalon* motor_d;
    CANTalon* motor_e;
    CANTalon* motor_f;
    double encoder_distance[4];
public:
    Chassis();
    ~Chassis();
    void Drive(double vX, double vY, double vZ, double Throttle, double k);
    void InitDefaultCommand();
    bool fieldCentered;
    double* EncoderDistance();
    void ZeroEncoders();
};

#endif
