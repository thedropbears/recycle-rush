#include <Commands/PID/ResetGyro.h>


ResetGyro :: ResetGyro(): CommandBase ("ResetGyro"){
    Requires(CommandBase::imu);
    SetInterruptible(false);
    SetRunWhenDisabled(true);
}

void ResetGyro::Initialize(){
    CommandBase::imu->Zero();
}

void ResetGyro::Execute(){
}

bool ResetGyro::IsFinished(){
    return true;
}

void ResetGyro::End(){

}

void ResetGyro::Interrupted(){
}
