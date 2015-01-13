#include "GyroReset.h"


GyroReset :: GyroReset(): Command ("GyroReset"){
    Requires(CommandBase::imu);
}

void GyroReset::Initialize(){
    CommandBase::imu->Zero();
}

void GyroReset::Execute(){
}

bool GyroReset::IsFinished(){
    return true;
}

void GyroReset::End(){

}

void GyroReset::Interrupted(){
}
