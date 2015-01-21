#include "ElevatorUp.h"
#include <RobotMap.h>

ElevatorUp :: ElevatorUp(): CommandBase ("ElevatorUp"){
}

void ElevatorUp::Initialize(){
    Requires(elevator);
}

void ElevatorUp::Execute(){

}

bool ElevatorUp::IsFinished(){
    return false;
}

void ElevatorUp::End(){

}

void ElevatorUp::Interrupted(){
}
