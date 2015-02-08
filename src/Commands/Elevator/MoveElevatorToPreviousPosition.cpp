#include "MoveElevatorToPreviousPosition.h"

MoveElevatorToPreviousPosition :: MoveElevatorToPreviousPosition(): CommandBase ("MoveElevatorToPreviousPosition"){
    Requires(elevator);
}

void MoveElevatorToPreviousPosition::Initialize(){
}

void MoveElevatorToPreviousPosition::Execute(){
    elevator->previousState();

}

bool MoveElevatorToPreviousPosition::IsFinished(){
    return true;
}

void MoveElevatorToPreviousPosition::End(){
}

void MoveElevatorToPreviousPosition::Interrupted(){
}
