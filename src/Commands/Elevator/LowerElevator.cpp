#include "LowerElevator.h"

LowerElevator :: LowerElevator(): CommandBase ("LowerElevator"){
    Requires(elevator);
}

void LowerElevator::Initialize(){

}

void LowerElevator::Execute(){
    elevator->driveMotor(-WINCH_MOTOR_SPEED);
}

bool LowerElevator::IsFinished(){
    return false;
}

void LowerElevator::End(){
    elevator->driveMotor(0.0);
}

void LowerElevator::Interrupted(){
    End();
}
