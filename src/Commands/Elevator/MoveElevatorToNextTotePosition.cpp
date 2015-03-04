#include "MoveElevatorToNextTotePosition.h"

MoveElevatorToNextTotePosition :: MoveElevatorToNextTotePosition(): CommandBase ("MoveElevatorToNextTotePosition"){
    Requires(elevator);
}

void MoveElevatorToNextTotePosition::Initialize(){
    elevator->nextState();
    if((elevator->getCommandedState() == elevator->states::READYSTACK1) || (elevator->getCommandedState() == elevator->states::READYSTACK2)) {
        elevator->nextState();
    }
}

void MoveElevatorToNextTotePosition::Execute(){

}

bool MoveElevatorToNextTotePosition::IsFinished(){
    return !elevator->changingState;
}

void MoveElevatorToNextTotePosition::End(){
}

void MoveElevatorToNextTotePosition::Interrupted(){

}
