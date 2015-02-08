#include <Commands/Auton/BinToteAuto.h>
#include <Commands/Elevator/MoveElevatorToNextPosition.h>
#include <Commands/Move/RotateOnSpot.h>
#include "../Move/MoveForward.h"

BinToteAuto::BinToteAuto() {
    AddSequential(new MoveElevatorToNextPosition());
    AddSequential(new MoveForward(TO_TOTE));
    AddSequential(new MoveElevatorToNextPosition());
    AddSequential(new RotateOnSpot(90.0));
    AddSequential(new MoveForward(TO_SCORING_ZONE));
}
