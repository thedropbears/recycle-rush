#include "RaiseElevatorOverride.h"

RaiseElevatorOverride :: RaiseElevatorOverride(): CommandBase ("RaiseElevatorOverride"){
    Requires(elevator);

}

void RaiseElevatorOverride::Initialize(){
}

void RaiseElevatorOverride::Execute(){
    elevator->upOverride();
}

bool RaiseElevatorOverride::IsFinished(){
    return false;
}

void RaiseElevatorOverride::End(){
    elevator->overriding = false;
    elevator->driveMotor(0.0);
}

void RaiseElevatorOverride::Interrupted(){
    End();
}
