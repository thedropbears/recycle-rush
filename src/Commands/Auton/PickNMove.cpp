#include <Commands/Move/RotateOnSpot.h>
#include "PickNMove.h"
#include "../Elevator/NextElevatorPosition.h"
#include "MoveForward.h"

PickNMove::PickNMove() {
    AddSequential(new NextElevatorPosition());
    AddSequential(new MoveForward(TO_TOTE));
    AddSequential(new NextElevatorPosition());
    AddSequential(new RotateOnSpot(90.0));
    AddSequential(new MoveForward(TO_SCORING_ZONE));
}
