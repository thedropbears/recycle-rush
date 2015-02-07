#include "ToElevatorPosition.h"

ToElevatorPosition :: ToElevatorPosition(Elevator::states toState): CommandBase ("ToElevatorPosition"){
    this->commandedState = toState;
    Requires(elevator);
}

void ToElevatorPosition::Initialize(){
}

void ToElevatorPosition::Execute(){
    elevator->toState(commandedState);

}

bool ToElevatorPosition::IsFinished(){
    return !elevator->changingState;
}

void ToElevatorPosition::End(){
}

void ToElevatorPosition::Interrupted(){
    End();
}
