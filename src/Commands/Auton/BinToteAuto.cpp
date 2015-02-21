#include "BinToteAuto.h"
#include <Commands/Elevator/MoveElevatorToNextPosition.h>
#include <Commands/Move/RotateOnSpot.h>
#include <Commands/Move/MoveForward.h>

BinToteAuto::BinToteAuto() {
    AddSequential(new MoveElevatorToNextPosition());
    AddSequential(new MoveElevatorToNextPosition());
    AddSequential(new MoveForward(0.65));
    AddSequential(new MoveElevatorToNextPosition());
    AddSequential(new RotateOnSpot(-90.0));
    AddSequential(new MoveForward(3.0));
}
