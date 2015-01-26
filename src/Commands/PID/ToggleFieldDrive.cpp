#include "ToggleFieldDrive.h"
#include <RobotMap.h>

ToggleFieldDrive :: ToggleFieldDrive(): CommandBase ("ToggleFieldDrive"){
    Requires(chassis);
}

void ToggleFieldDrive::Initialize(){
    chassis->fieldCentered = !chassis->fieldCentered;
    imu->Zero();
}

void ToggleFieldDrive::Execute(){
}

bool ToggleFieldDrive::IsFinished(){
    return true;
}

void ToggleFieldDrive::End(){

}

void ToggleFieldDrive::Interrupted(){
}
