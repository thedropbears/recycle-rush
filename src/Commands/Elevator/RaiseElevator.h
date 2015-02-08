#ifndef RAISEELEVATOR
#define RAISEELEVATOR

#include <CommandBase.h>

class RaiseElevator: public CommandBase{
public:
    RaiseElevator();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
