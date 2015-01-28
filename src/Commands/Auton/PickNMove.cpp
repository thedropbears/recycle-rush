#include "PickNMove.h"
#include "../Move/MoveToTote.h"
#include "../Move/Turn90.h"
#include "../Elevator/NextElevatorPosition.h"
#include "../Move/DriveForward.h"

PickNMove::PickNMove() {
    AddSequential(new NextElevatorPosition);
    AddSequential(new MoveToTote);
    AddSequential(new NextElevatorPosition);
    AddSequential(new Turn90);
    AddSequential(new DriveForward);
}
