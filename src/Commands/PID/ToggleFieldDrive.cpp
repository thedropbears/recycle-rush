#include "ToggleFieldDrive.h"

ToggleFieldDrive :: ToggleFieldDrive(): CommandBase ("ToggleFieldDrive"){
    Requires(imu);
}

void ToggleFieldDrive::Initialize(){
    chassis->fieldCentered = !chassis->fieldCentered;
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
