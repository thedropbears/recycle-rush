#ifndef ELEVATORDOWN
#define ELEVATORDOWN

#include <CommandBase.h>

class ElevatorDown: public CommandBase{
public:
    ElevatorDown();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
