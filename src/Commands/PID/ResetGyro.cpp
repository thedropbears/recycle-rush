#include <Commands/PID/ResetGyro.h>


ResetGyro :: ResetGyro(): CommandBase ("ResetGyro"){
    Requires(CommandBase::imu);
    SetInterruptible(false);
    SetRunWhenDisabled(true);
}

void ResetGyro::Initialize(){
    CommandBase::imu->Zero();
    CommandBase::chassis->SetHeading(0.0);
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
