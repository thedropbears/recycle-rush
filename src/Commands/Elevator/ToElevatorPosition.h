#ifndef TOELEVATORPOSITION
#define TOELEVATORPOSITION

#include <CommandBase.h>

class ToElevatorPosition: public CommandBase{
public:
    ToElevatorPosition();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
