#include <Commands/Auton/BinToteAuto.h>
#include <Commands/Move/RotateOnSpot.h>
#include "../Elevator/NextElevatorPosition.h"
#include "../Move/MoveForward.h"

BinToteAuto::BinToteAuto() {
    AddSequential(new NextElevatorPosition());
    AddSequential(new MoveForward(TO_TOTE));
    AddSequential(new NextElevatorPosition());
    AddSequential(new RotateOnSpot(90.0));
    AddSequential(new MoveForward(TO_SCORING_ZONE));
}
