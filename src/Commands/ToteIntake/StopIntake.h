#ifndef STOPINTAKE
#define STOPINTAKE

#include <CommandBase.h>

class StopIntake: public CommandBase{
public:
    StopIntake();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
