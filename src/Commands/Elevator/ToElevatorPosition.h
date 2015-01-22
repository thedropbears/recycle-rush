#ifndef TOELEVATORPOSITION
#define TOELEVATORPOSITION

#include <CommandBase.h>

class ToElevatorPosition: public CommandBase{
public:
    ToElevatorPosition(Elevator::states toState);
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();

private:
    Elevator::states commandedState;
};

#endif
