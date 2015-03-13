#ifndef RAISEELEVATOROVERRIDE
#define RAISEELEVATOROVERRIDE

#include <CommandBase.h>

class RaiseElevatorOverride: public CommandBase{
public:
    RaiseElevatorOverride();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
