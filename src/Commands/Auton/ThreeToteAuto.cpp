#include "ThreeToteAuto.h"
#include <Commands/Elevator/MoveElevatorToNextPosition.h>
#include <Commands/Elevator/GoToElevatorPosition.h>
#include <Commands/Move/RotateOnSpot.h>
#include <Commands/Move/MoveForward.h>
#include "GrabToteWhileMoving.h"
#include <Subsystems/Move/Elevator.h>


//robot must turn counter clockwise


ThreeToteAuto::ThreeToteAuto() {
    AddSequential(new GoToElevatorPosition(Elevator::states::READYTOTE2));
    AddSequential(new MoveForward(0.60));
    AddSequential(new GrabToteWhileMoving());
    AddSequential(new GrabToteWhileMoving());
    AddSequential(new RotateOnSpot(-90.0));
    AddSequential(new MoveForward(TO_SCORING_ZONE));
    AddSequential(new GoToElevatorPosition(Elevator::states::READYTOTE3));
}
