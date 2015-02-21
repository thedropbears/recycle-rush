#include <Commands/Elevator/GoToElevatorPosition.h>

GoToElevatorPosition :: GoToElevatorPosition(Elevator::states toState): CommandBase ("GoToElevatorPosition"){
    this->commandedState = toState;
    Requires(elevator);
}

void GoToElevatorPosition::Initialize(){
    elevator->toState(commandedState);
}

void GoToElevatorPosition::Execute(){


}

bool GoToElevatorPosition::IsFinished(){
    return !elevator->changingState;
}

void GoToElevatorPosition::End(){
}

void GoToElevatorPosition::Interrupted(){
    End();
}
