#ifndef LOWERELEVATOR
#define LOWERELEVATOR

#include <CommandBase.h>

class LowerElevator: public CommandBase{
public:
    LowerElevator();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
