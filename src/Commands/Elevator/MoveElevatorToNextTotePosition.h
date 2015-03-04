#ifndef MOVEELEVATORTONEXTTOTEPOSITION
#define MOVEELEVATORTONEXTTOTEPOSITION

#include <CommandBase.h>

class MoveElevatorToNextTotePosition: public CommandBase{
public:
    MoveElevatorToNextTotePosition();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
