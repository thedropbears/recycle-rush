#include "PickNMove.h"
#include "../Move/Turn90.h"
#include "../Elevator/NextElevatorPosition.h"
#include "MoveForward.h"

PickNMove::PickNMove() {
    AddSequential(new NextElevatorPosition());
    AddSequential(new MoveForward(TO_TOTE));
    AddSequential(new NextElevatorPosition());
    AddSequential(new Turn90(Turn90::directions::LEFT));
    AddSequential(new MoveForward(TO_SCORING_ZONE));
}
