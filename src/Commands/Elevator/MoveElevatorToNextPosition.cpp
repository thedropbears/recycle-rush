#include <Commands/Elevator/MoveElevatorToNextPosition.h>

MoveElevatorToNextPosition :: MoveElevatorToNextPosition(): CommandBase ("MoveElevatorToNextPosition"){
    Requires(elevator);
}

void MoveElevatorToNextPosition::Initialize(){
}

void MoveElevatorToNextPosition::Execute(){
    elevator->nextState();
}

bool MoveElevatorToNextPosition::IsFinished(){
    return true;
}

void MoveElevatorToNextPosition::End(){
}

void MoveElevatorToNextPosition::Interrupted(){

}
