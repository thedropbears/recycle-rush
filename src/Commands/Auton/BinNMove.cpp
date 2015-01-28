#include "BinNMove.h"
#include "../Elevator/NextElevatorPosition.h"
#include "../Move/DriveForward.h"

BinNMove::BinNMove() {
    AddSequential(new NextElevatorPosition());
    AddSequential(new DriveForward());

}
