#include "IntakeTote.h"

IntakeTote :: IntakeTote(): CommandBase ("IntakeTote"){
    Requires(toteIntake);
    this->SetTimeout(3.0);
}

void IntakeTote::Initialize(){
}

void IntakeTote::Execute(){
    toteIntake->DriveIn();
}

bool IntakeTote::IsFinished(){
    return false;
}

void IntakeTote::End(){
    toteIntake->Stop();
}

void IntakeTote::Interrupted(){
    End();
}
