#include "ElevatorDown.h"

ElevatorDown :: ElevatorDown(): CommandBase ("ElevatorDown"){
    Requires(elevator);
}

void ElevatorDown::Initialize(){

}

void ElevatorDown::Execute(){
    elevator->driveMotor(-WINCH_MOTOR_SPEED);
}

bool ElevatorDown::IsFinished(){
    return false;
}

void ElevatorDown::End(){
    elevator->driveMotor(0.0);
}

void ElevatorDown::Interrupted(){
    End();
}
