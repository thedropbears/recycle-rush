#include <Commands/Elevator/PreviousElevatorPosition.h>
#include <RobotMap.h>

PreviousElevatorPosition :: PreviousElevatorPosition(): CommandBase ("PreviousElevatorPosition"){
    Requires(elevator);
}

void PreviousElevatorPosition::Initialize(){
}

void PreviousElevatorPosition::Execute(){
    elevator->previousState();

}

bool PreviousElevatorPosition::IsFinished(){
    return true;
}

void PreviousElevatorPosition::End(){
}

void PreviousElevatorPosition::Interrupted(){
}
