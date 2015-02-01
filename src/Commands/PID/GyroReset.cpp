#include "GyroReset.h"


GyroReset :: GyroReset(): CommandBase ("GyroReset"){
    Requires(CommandBase::imu);
    SetInterruptible(false);
    SetRunWhenDisabled(true);
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
