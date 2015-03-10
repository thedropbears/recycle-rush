#ifndef TOTEINTAKE
#define TOTEINTAKE

#include "WPILib.h"

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
