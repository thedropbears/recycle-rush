#include "ThreeToteAuto.h"
#include <Commands/Elevator/MoveElevatorToNextPosition.h>
#include <Commands/Elevator/GoToElevatorPosition.h>
#include <Commands/Move/RotateOnSpot.h>
#include <Commands/Move/MoveForward.h>
#include "GrabToteWhileMoving.h"
#include <Subsystems/Move/Elevator.h>
#include <Commands/ToteIntake/StopIntake.h>
#include <Commands/ToteIntake/OutputTote.h>
#include <Commands/ToteIntake/IntakeTote.h>


//robot must turn counter clockwise


ThreeToteAuto::ThreeToteAuto() {
    AddSequential(new GoToElevatorPosition(Elevator::states::READYTOTE2));
    AddSequential(new MoveForward(0.60));
    AddParallel(new IntakeTote());
    AddSequential(new GrabToteWhileMoving());
    AddSequential(new GrabToteWhileMoving());
    AddSequential(new StopIntake());
    AddSequential(new RotateOnSpot(-90.0));
    AddSequential(new MoveForward(TO_SCORING_ZONE));
    AddSequential(new GoToElevatorPosition(Elevator::states::READYTOTE3));
    AddSequential(new StopIntake());
    AddSequential(new OutputTote());
}
