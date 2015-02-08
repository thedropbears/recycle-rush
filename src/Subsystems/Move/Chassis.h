#ifndef CHASSIS_H
#define CHASSIS_H

#include "WPILib.h"
#define WHEEL_CIRCUMFERENCE 47.8778621 //cm

#include <lib-4774/subsystems/Mpu6050.h>
#include <Subsystems/PID/GyroCorrection.h>

class Chassis: public Subsystem {
private:
    CANTalon* motor_a;
    CANTalon* motor_b;
    CANTalon* motor_c;
    CANTalon* motor_d;
    CANTalon* motor_e;
    CANTalon* motor_f;
    double encoder_distance[4];
    bool momentum;

    GyroCorrection *correction;
    PIDController *gyro_pid;
    PowerDistributionPanel *pdp;
public:
    Chassis();
    ~Chassis();
    void Drive(double vX, double vY, double vZ, double Throttle);
    void InitDefaultCommand();
    bool fieldCentered;
    void EncoderDistance(double*);
    void ZeroEncoders();
    void Stop();
    void SetHeading(double newHeading);
    void HeadingChange(double change);
    void EnablePID();
    void DisablePID();
    bool OnTarget();
    bool PIDEnabled();
};

#endif
