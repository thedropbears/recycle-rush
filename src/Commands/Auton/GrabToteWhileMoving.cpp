#include "GrabToteWhileMoving.h"
#include "Commands/Elevator/MoveElevatorToNextTotePosition.h"
#include <Commands/Move/MoveForward.h>
#include <Commands/ToteIntake/IntakeTote.h>

GrabToteWhileMoving::GrabToteWhileMoving() {
    AddParallel(new MoveForward(1.44));
    AddParallel(new MoveElevatorToNextTotePosition());
    AddParallel(new IntakeTote());
}
