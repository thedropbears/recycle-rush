#ifndef IRTRIGGER
#define IRTRIGGER

#include <WPILib.h>
#include <Subsystems/Move/Elevator.h>

#define IR_TRIPPED_DISTANCE 500

class IRTrigger: public Trigger {
public:
    IRTrigger(Elevator::switches toMonitor);
    bool Get();
private:
    AnalogInput* ir;
};

#endif
