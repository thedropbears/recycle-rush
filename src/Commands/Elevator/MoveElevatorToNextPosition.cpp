#include "MoveElevatorToNextPosition.h"

MoveElevatorToNextPosition :: MoveElevatorToNextPosition(): CommandBase ("MoveElevatorToNextPosition"){
    Requires(elevator);
}

void MoveElevatorToNextPosition::Initialize(){
    elevator->nextState();
}

void MoveElevatorToNextPosition::Execute(){

}

bool MoveElevatorToNextPosition::IsFinished(){
    return true;
}

void MoveElevatorToNextPosition::End(){
}

void MoveElevatorToNextPosition::Interrupted(){

}
