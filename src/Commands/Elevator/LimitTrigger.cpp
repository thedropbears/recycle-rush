#include "LimitTrigger.h"
#include "RobotMap.h"

LimitTrigger::LimitTrigger(Elevator::switches toMonitor) {
    int dio_id;
    switch (toMonitor) {  // no pun intended
    case Elevator::switches::BINSWITCH:
        dio_id = BIN_CHANNEL; break;
    case Elevator::switches::READYSWITCHTOP:
        dio_id = READY_CHANNEL_TOP; break;
    case Elevator::switches::READYSWITCHBOTTOM:
        dio_id = READY_CHANNEL_BOTTOM; break;
    case Elevator::switches::ENDSWITCH:
        dio_id = END_CHANNEL; break;
    case Elevator::switches::NOSWITCH: break;
    }
    if(dio_id) {
        di = new DigitalInput(dio_id);
    }
}

bool LimitTrigger::Get() {
    if(di) {
        return di->Get();
    }
    return false;
}
