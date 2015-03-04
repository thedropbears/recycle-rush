#include "MoveElevatorToPreviousTotePosition.h"

MoveElevatorToPreviousTotePosition :: MoveElevatorToPreviousTotePosition(): CommandBase ("MoveElevatorToPreviousTotePosition"){
    Requires(elevator);
}

void MoveElevatorToPreviousTotePosition::Initialize(){
    elevator->previousState();
    if((elevator->getCommandedState() == elevator->states::READYSTACK1) || (elevator->getCommandedState() == elevator->states::READYSTACK2)) {
        elevator->previousState();
    }
}

void MoveElevatorToPreviousTotePosition::Execute(){

}

bool MoveElevatorToPreviousTotePosition::IsFinished(){
    return !elevator->changingState;
}

void MoveElevatorToPreviousTotePosition::End(){
}

void MoveElevatorToPreviousTotePosition::Interrupted(){

}
