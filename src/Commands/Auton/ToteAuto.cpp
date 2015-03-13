#include "ToteAuto.h"
#include <Commands/Elevator/MoveElevatorToNextPosition.h>
#include <Commands/Move/MoveForward.h>
#include <Commands/Move/RotateOnSpot.h>

//robot must turn counter clockwise

ToteAuto::ToteAuto() {
    AddSequential(new RotateOnSpot(90));
    AddSequential(new MoveForward(0.5));
    AddSequential(new MoveElevatorToNextPosition());
    AddSequential(new MoveElevatorToNextPosition());
    AddSequential(new RotateOnSpot(-90));
    AddSequential(new MoveForward(3.0));
}
