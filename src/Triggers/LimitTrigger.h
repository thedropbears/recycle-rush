#ifndef LIMITTRIGGER
#define LIMITTRIGGER

#include <WPILib.h>

class LimitTrigger: public Trigger {
public:
    LimitTrigger(uint32_t);
    bool Get();
private:
    DigitalInput* di;
};

#endif
