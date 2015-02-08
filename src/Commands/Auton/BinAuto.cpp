#include <Commands/Auton/BinAuto.h>
#include "../Move/MoveForward.h"
#include "../Elevator/NextElevatorPosition.h"

BinAuto::BinAuto() {
    AddSequential(new NextElevatorPosition());
    AddSequential(new MoveForward(TO_SCORING_ZONE));
}
