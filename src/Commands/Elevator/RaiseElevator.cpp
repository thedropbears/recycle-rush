#include <Commands/Elevator/RaiseElevator.h>

RaiseElevator :: RaiseElevator(): CommandBase ("RaiseElevator"){
    Requires(elevator);

}

void RaiseElevator::Initialize(){
}

void RaiseElevator::Execute(){
    elevator->driveMotor(WINCH_MOTOR_SPEED);
}

bool RaiseElevator::IsFinished(){
    return false;
}

void RaiseElevator::End(){
    elevator->driveMotor(0.0);
}

void RaiseElevator::Interrupted(){
    End();
}
