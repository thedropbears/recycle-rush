#include "OutputTote.h"

OutputTote :: OutputTote(): CommandBase ("OutputTote"){
    Requires(toteIntake);
}

void OutputTote::Initialize(){

}

void OutputTote::Execute(){
    toteIntake->DriveOut();
}

bool OutputTote::IsFinished(){
    return false;
}

void OutputTote::End(){
    toteIntake->Stop();
}

void OutputTote::Interrupted(){
    End();
}
