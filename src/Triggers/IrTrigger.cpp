#include "IrTrigger.h"

#include <RobotMap.h>

#define IR_TRIPPED_DISTANCE 500

IrTrigger::IrTrigger(uint32_t channel): AnalogInput(channel) {}

bool IrTrigger::Get() {
    if(this->GetValue() < IR_TRIPPED_DISTANCE) {
        return true;
    }
    return false;
}
