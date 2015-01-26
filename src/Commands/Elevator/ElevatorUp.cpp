#include "ElevatorUp.h"
#include <RobotMap.h>

ElevatorUp :: ElevatorUp(): CommandBase ("ElevatorUp"){
    Requires(elevator);

}

void ElevatorUp::Initialize(){
}

void ElevatorUp::Execute(){
    elevator->driveMotor(WINCH_MOTOR_SPEED);
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
