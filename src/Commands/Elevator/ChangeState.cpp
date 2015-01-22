#include "ChangeState.h"
#include <RobotMap.h>

ChangeState :: ChangeState(Elevator::switches tripped): CommandBase ("ChangeState"){
    this->tripped = tripped;
}

void ChangeState::Initialize(){
    switch (tripped) {  // no pun intended
    case Elevator::switches::BINSWITCH:
        CommandBase::elevator->binSwitchTripped = true;
        break;
    case Elevator::switches::READYSWITCHTOP:
        CommandBase::elevator->readySwitchTopTripped = true;
        break;
    case Elevator::switches::READYSWITCHBOTTOM:
        CommandBase::elevator->readySwitchBottomTripped = true;
        break;
    case Elevator::switches::ENDSWITCH:
        CommandBase::elevator->endSwitchTripped = true;
        break;
    }
}

void ChangeState::Execute(){
}

bool ChangeState::IsFinished(){
    return false;
}

void ChangeState::End(){
}

void ChangeState::Interrupted(){
    End();
}
