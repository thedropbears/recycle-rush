#ifndef STOPELEVATOR
#define STOPELEVATOR

#include <CommandBase.h>

class StopElevator: public CommandBase{
public:
    StopElevator();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
