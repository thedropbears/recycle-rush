#ifndef PREVIOUSELEVATORPOSITION
#define PREVIOUSELEVATORPOSITION

#include <CommandBase.h>

class PreviousElevatorPosition: public CommandBase{
public:
    PreviousElevatorPosition();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
