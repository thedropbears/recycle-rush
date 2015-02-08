#include "BinAuto.h"
#include <Commands/Elevator/MoveElevatorToNextPosition.h>
#include <Commands/Move/MoveForward.h>

BinAuto::BinAuto() {
    AddSequential(new MoveElevatorToNextPosition());
    AddSequential(new MoveForward(TO_SCORING_ZONE));
}
