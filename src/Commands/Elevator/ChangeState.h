#ifndef CHANGESTATE
#define CHANGESTATE

#include <CommandBase.h>
#include <Subsystems/Move/Elevator.h>

class ChangeState: public CommandBase{
public:
    ChangeState(Elevator::switches tripped, Elevator *elevator);
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();

private:
    Elevator::switches tripped;
};

#endif
