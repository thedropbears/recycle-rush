#include "LowerElevatorOverride.h"

LowerElevatorOverride :: LowerElevatorOverride(): CommandBase ("LowerElevatorOverride"){
    Requires(elevator);

}

void LowerElevatorOverride::Initialize(){
}

void LowerElevatorOverride::Execute(){
    elevator->downOverride();
}

bool LowerElevatorOverride::IsFinished(){
    return false;
}

void LowerElevatorOverride::End(){
    elevator->overriding = false;
    elevator->driveMotor(0.0);
}

void LowerElevatorOverride::Interrupted(){
    End();
}
