#ifndef IRTRIGGER
#define IRTRIGGER

#include <WPILib.h>

class IrTrigger: public Trigger, public AnalogInput {
public:
    IrTrigger(uint32_t);
    bool Get();
};

#endif
