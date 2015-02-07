#ifndef LIMITTRIGGER
#define LIMITTRIGGER

#include <WPILib.h>
#include <Subsystems/Move/Elevator.h>


class LimitTrigger: public Trigger {
public:
    LimitTrigger(Elevator::switches toMonitor);
    bool Get();
private:
    DigitalInput* di;
};

#endif
