#ifndef MOVEELEVATORTOPREVIOUSPOSITION
#define MOVEELEVATORTOPREVIOUSPOSITION

#include <CommandBase.h>

class MoveElevatorToPreviousPosition: public CommandBase{
public:
    MoveElevatorToPreviousPosition();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
