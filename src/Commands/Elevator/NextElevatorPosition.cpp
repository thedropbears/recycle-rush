#include "NextElevatorPosition.h"

NextElevatorPosition :: NextElevatorPosition(): CommandBase ("NextElevatorPosition"){
    Requires(elevator);
}

void NextElevatorPosition::Initialize(){
}

void NextElevatorPosition::Execute(){
    elevator->nextState();
}

bool NextElevatorPosition::IsFinished(){
    return true;
}

void NextElevatorPosition::End(){
}

void NextElevatorPosition::Interrupted(){

}
