#include <Commands/Elevator/NextElevatorPosition.h>
#include <RobotMap.h>

NextElevatorPosition :: NextElevatorPosition(): CommandBase ("NextElevatorPosition"){
}

void NextElevatorPosition::Initialize(){
    Requires(elevator);
}

void NextElevatorPosition::Execute(){
    elevator->nextState();
}

bool NextElevatorPosition::IsFinished(){

    return true;
}

void NextElevatorPosition::End(){
    elevator->stopMotor();

}

void NextElevatorPosition::Interrupted(){

}
