#include <Commands/Elevator/PreviousElevatorPosition.h>
#include <RobotMap.h>

PreviousElevatorPosition :: PreviousElevatorPosition(): CommandBase ("PreviousElevatorPosition"){
}

void PreviousElevatorPosition::Initialize(){
    Requires(elevator);
}

void PreviousElevatorPosition::Execute(){
    elevator->driveMotor(-1.0);
}

bool PreviousElevatorPosition::IsFinished(){
    return true;
}

void PreviousElevatorPosition::End(){
    elevator->stopMotor();
}

void PreviousElevatorPosition::Interrupted(){
}
