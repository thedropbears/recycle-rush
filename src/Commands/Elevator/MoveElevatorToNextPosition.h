#ifndef MOVEELEVATORTONEXTPOSITION
#define MOVEELEVATORTONEXTPOSITION

#include <CommandBase.h>

class MoveElevatorToNextPosition: public CommandBase{
public:
    MoveElevatorToNextPosition();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
