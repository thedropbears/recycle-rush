#ifndef LIGHTRING
#define LIGHTRING

#include "WPILib.h"

#include "RobotMap.h"

#include <time.h>

class LightRing: public Subsystem {
public:
    LightRing();
    ~LightRing();
    void ToggleState();
    double GetTimeSinceToggled(); // in sec
    void Off();
    void On();
private:
    time_t timeSinceToggled;
    Relay *lightRingRelay;
};

#endif
