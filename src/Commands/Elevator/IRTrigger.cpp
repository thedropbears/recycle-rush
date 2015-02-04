#include "IRTrigger.h"
#include "RobotMap.h"

IRTrigger::IRTrigger(Elevator::switches toMonitor) {
    int ir_id;
    switch (toMonitor) {  // no pun intended
    case Elevator::switches::READYSWITCHTOP:
        ir_id = READY_CHANNEL_TOP; break;
    case Elevator::switches::READYSWITCHBOTTOM:
        ir_id = READY_CHANNEL_BOTTOM; break;
    case Elevator::switches::ENDSWITCH:
        break;
    case Elevator::switches::NOSWITCH: break;
    }
    if(ir_id) {
        ir = new AnalogInput(ir_id);
    }
}

bool IRTrigger::Get() {
    if(ir->GetValue() < IR_TRIPPED_DISTANCE) {
        return true;
    }
    return false;
}
