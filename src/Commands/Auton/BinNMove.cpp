#include "BinNMove.h"
#include "../Elevator/NextElevatorPosition.h"

BinNMove::BinNMove() {
    AddSequential(new NextElevatorPosition());

}
