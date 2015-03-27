#include "BinAuto.h"
#include <Commands/Elevator/MoveElevatorToNextPosition.h>
#include <Commands/Move/MoveForward.h>
#include <Commands/PID/ResetGyro.h>

//robot must turn counter clockwise

BinAuto::BinAuto() {
    AddSequential(new MoveElevatorToNextPosition());
    AddSequential(new MoveElevatorToNextPosition());
    AddSequential(new MoveForward(-2.6));
}
