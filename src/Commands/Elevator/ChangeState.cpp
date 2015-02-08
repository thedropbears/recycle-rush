#include "ChangeState.h"

ChangeState :: ChangeState(Elevator::switches tripped, Elevator *elevator): CommandBase ("ChangeState"){
    Requires(elevator);
    this->tripped = tripped;
}

void ChangeState::Initialize(){
    switch (tripped) {  // no pun intended
    case Elevator::switches::READYSWITCHTOP:
        CommandBase::elevator->readySwitchTopTripped = true;
        CommandBase::elevator->atReadySwitchTop();
        break;
    case Elevator::switches::READYSWITCHBOTTOM:
        CommandBase::elevator->readySwitchBottomTripped = true;
        CommandBase::elevator->atReadySwitchBottom();
        break;
    case Elevator::switches::ENDSWITCH:
        CommandBase::elevator->endSwitchTripped = true;
        CommandBase::elevator->atEndSwitch();
        break;
    case Elevator::switches::NOSWITCH:
        break;
    }

}

void ChangeState::Execute(){
}

bool ChangeState::IsFinished(){
    return true;
}

void ChangeState::End(){
}

void ChangeState::Interrupted(){
    End();
}
