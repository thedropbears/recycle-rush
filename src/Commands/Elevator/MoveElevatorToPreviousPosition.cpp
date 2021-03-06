#include "MoveElevatorToPreviousPosition.h"

MoveElevatorToPreviousPosition :: MoveElevatorToPreviousPosition(): CommandBase ("MoveElevatorToPreviousPosition"){
    Requires(elevator);
}

void MoveElevatorToPreviousPosition::Initialize(){
    elevator->previousState();
}

void MoveElevatorToPreviousPosition::Execute(){


}

bool MoveElevatorToPreviousPosition::IsFinished(){
    return !elevator->changingState;
}

void MoveElevatorToPreviousPosition::End(){
}

void MoveElevatorToPreviousPosition::Interrupted(){
}
