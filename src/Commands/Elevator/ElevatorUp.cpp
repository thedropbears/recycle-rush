#include "ElevatorUp.h"
#include <RobotMap.h>

ElevatorUp :: ElevatorUp(): CommandBase ("ElevatorUp"){
}

void ElevatorUp::Initialize(){
    Requires(elevator);
}

void ElevatorUp::Execute(){
    elevator->driveMotor(1.0);
}

bool ElevatorUp::IsFinished(){
    return false;
}

void ElevatorUp::End(){
    elevator->driveMotor(0.0);
}

void ElevatorUp::Interrupted(){
    End();
}
