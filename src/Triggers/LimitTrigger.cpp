#include "LimitTrigger.h"
#include "RobotMap.h"

LimitTrigger::LimitTrigger(uint32_t channel){
    di = new DigitalInput(channel);
}

bool LimitTrigger::Get() {
    return di->Get();
}
