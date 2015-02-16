#include "StopElevator.h"

StopElevator :: StopElevator(): CommandBase ("StopElevator"){
    Requires(elevator);
}

void StopElevator::Initialize(){
    elevator->stopMotor();
}

void StopElevator::Execute(){
    elevator->stopMotor();
}

bool StopElevator::IsFinished(){
    return true;
}

void StopElevator::End(){
}

void StopElevator::Interrupted(){

}
