#ifndef GYROSOURCE
#define GYROSOURCE

#include "WPILib.h"

class GyroSource:public PIDSource {
public:
    double PIDGet();
};

#endif
