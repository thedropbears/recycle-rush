#ifndef TOTEINTAKE
#define TOTEINTAKE

#include "WPILib.h"

const double TOTE_INTAKE_SPEED = 0.4; // speed to go *clockwise*
const double TOTE_OUTPUT_SPEED = 0.4;

class ToteIntake: public Subsystem {
public:
    ToteIntake();
    void DriveIn();
    void DriveOut();
    void Stop();
private:
    CANTalon* left_motor;
    CANTalon* right_motor;

};

#endif
