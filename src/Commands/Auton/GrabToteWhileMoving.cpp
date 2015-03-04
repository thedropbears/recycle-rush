#include "GrabToteWhileMoving.h"
#include "Commands/Elevator/MoveElevatorToNextTotePosition.h"
#include <Commands/Move/MoveForward.h>

GrabToteWhileMoving::GrabToteWhileMoving() {
    AddParallel(new MoveForward(1.44));
    AddParallel(new MoveElevatorToNextTotePosition());
}
