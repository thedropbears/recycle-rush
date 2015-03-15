#include <Commands/PID/ResetGyro.h>


ResetGyro :: ResetGyro(): CommandBase ("ResetGyro"){
    Requires(imu);
    Requires(chassis);
    SetInterruptible(false);
    SetRunWhenDisabled(true);
}

void ResetGyro::Initialize(){
    CommandBase::imu->Zero();
    CommandBase::chassis->SetHeading(imu->GetYaw());
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
