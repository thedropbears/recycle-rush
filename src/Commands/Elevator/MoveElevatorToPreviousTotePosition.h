#ifndef MOVEELEVATORTOPREVIOUSTOTEPOSITION
#define MOVEELEVATORTOPREVIOUSTOTEPOSITION

#include <CommandBase.h>

class MoveElevatorToPreviousTotePosition: public CommandBase{
public:
    MoveElevatorToPreviousTotePosition();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
