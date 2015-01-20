#ifndef ELEVATORUP
#define ELEVATORUP

#include <CommandBase.h>

class ElevatorUp: public CommandBase{
public:
    ElevatorUp();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
