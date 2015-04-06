#include "WinchUpAuto.h"
#include <Commands/Elevator/MoveElevatorToNextPosition.h>
#include <Commands/Move/MoveForward.h>
#include <Commands/PID/ResetGyro.h>

//robot must turn counter clockwise

WinchUpAuto::WinchUpAuto() {
    AddSequential(new MoveElevatorToNextPosition());
    AddSequential(new MoveElevatorToNextPosition());
}
