#include <Commands/Elevator/NextElevatorPosition.h>
#include <RobotMap.h>

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
