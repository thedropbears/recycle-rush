#include "ToggleAtFrequency.h"

ToggleAtFrequency :: ToggleAtFrequency(double rate, double forTime): Command ("ToggleAtFrequency"){
    Requires(CommandBase::lightRing);
    this->rate = rate;
    this->forTime = forTime;
}

void ToggleAtFrequency::Initialize(){
    time(&startTime);

}

void ToggleAtFrequency::Execute(){
    if(difftime(time(NULL), startTime) > forTime && CommandBase::lightRing->GetTimeSinceToggled() >= (1/rate)) {
        CommandBase::lightRing->ToggleState();
    }
}

bool ToggleAtFrequency::IsFinished(){
    if(difftime(time(NULL), startTime) > forTime) {
        return true;
    } else {
        return false;
    }
}

void ToggleAtFrequency::End(){
    CommandBase::lightRing->Off();
}

void ToggleAtFrequency::Interrupted(){
    End();
}
