#ifndef TOGGLEATFREQUENCY
#define TOGGLEATFREQUENCY

#include <CommandBase.h>

#include <time.h>

class ToggleAtFrequency: public Command{
public:
    ToggleAtFrequency(double rate, double forTime=10); // rate is in hz, fortime is in seconds
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
private:
    time_t startTime;
    double rate, forTime;
};

#endif
