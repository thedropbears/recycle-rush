#include "BinToteAuto.h"
#include <Commands/Elevator/MoveElevatorToNextPosition.h>
#include <Commands/Move/RotateOnSpot.h>
#include <Commands/Move/MoveForward.h>

//robot must turn counter clockwise


BinToteAuto::BinToteAuto() {
    AddSequential(new MoveElevatorToNextPosition());
    AddSequential(new MoveElevatorToNextPosition());
    AddSequential(new MoveForward(0.65));
    AddSequential(new MoveElevatorToNextPosition());
    AddSequential(new RotateOnSpot(-90.0));
    AddSequential(new MoveForward(TO_SCORING_ZONE));
}
