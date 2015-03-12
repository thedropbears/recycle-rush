#include "StopIntake.h"

StopIntake :: StopIntake(): CommandBase ("StopIntake"){
    Requires(toteIntake);
}

void StopIntake::Initialize(){
    toteIntake->Stop();
}

void StopIntake::Execute(){
    toteIntake->Stop();
}

bool StopIntake::IsFinished(){
    return true;
}

void StopIntake::End(){
}

void StopIntake::Interrupted(){
    End();
}
