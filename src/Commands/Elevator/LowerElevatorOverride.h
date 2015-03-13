#ifndef LOWERELEVATOROVERRIDE
#define LOWERELEVATOROVERRIDE

#include <CommandBase.h>

class LowerElevatorOverride: public CommandBase{
public:
    LowerElevatorOverride();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
