#include <Commands/Elevator/ToElevatorPosition.h>
#include <RobotMap.h>

ToElevatorPosition :: ToElevatorPosition(Elevator::states toState): CommandBase ("ToElevatorPosition"){
    this->commandedState = toState;
    Requires(elevator);
}

void ToElevatorPosition::Initialize(){
    elevator->toState(commandedState);
}

void ToElevatorPosition::Execute(){

}

bool ToElevatorPosition::IsFinished(){
    return !elevator->changingState;
}

void ToElevatorPosition::End(){
}

void ToElevatorPosition::Interrupted(){
    End();
}
