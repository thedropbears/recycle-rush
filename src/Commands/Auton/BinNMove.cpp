#include <Commands/Auton/MoveForward.h>
#include "BinNMove.h"
#include "../Elevator/NextElevatorPosition.h"
#include "MoveForward.h"

BinNMove::BinNMove() {
    AddSequential(new NextElevatorPosition());
    AddSequential(new MoveForward(TO_SCORING_ZONE));
}
