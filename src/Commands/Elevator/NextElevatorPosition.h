#ifndef NEXTELEVATORPOSITION
#define NEXTELEVATORPOSITION

#include <CommandBase.h>

class NextElevatorPosition: public CommandBase{
public:
    NextElevatorPosition();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
