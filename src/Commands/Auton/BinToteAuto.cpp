#include "BinToteAuto.h"
#include <Commands/Elevator/MoveElevatorToNextPosition.h>
#include <Commands/Move/RotateOnSpot.h>
#include <Commands/Move/MoveForward.h>

BinToteAuto::BinToteAuto() {
    AddSequential(new MoveElevatorToNextPosition());
    SmartDashboard::PutString("Shit", "1");
    AddSequential(new MoveElevatorToNextPosition());
    SmartDashboard::PutString("Shit", "2");
    AddSequential(new MoveForward(0.65));
    SmartDashboard::PutString("Shit", "3");
    AddSequential(new MoveElevatorToNextPosition());
    SmartDashboard::PutString("Shit", "4");
    AddSequential(new RotateOnSpot(-90.0));
    SmartDashboard::PutString("Shit", "5");
    AddSequential(new MoveForward(3.0));
    SmartDashboard::PutString("Shit", "6");
}
