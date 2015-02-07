#include "BinNMove.h"

#include "MoveForward.h"
#include "../Elevator/NextElevatorPosition.h"

BinNMove::BinNMove() {
    AddSequential(new NextElevatorPosition());
    AddSequential(new MoveForward(TO_SCORING_ZONE));
}
