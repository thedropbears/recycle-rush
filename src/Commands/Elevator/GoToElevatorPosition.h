#ifndef GOTOELEVATORPOSITION
#define GOTOELEVATORPOSITION

#include <CommandBase.h>

class GoToElevatorPosition: public CommandBase{
public:
    GoToElevatorPosition(Elevator::states toState);
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();

private:
    Elevator::states commandedState;
};

#endif
