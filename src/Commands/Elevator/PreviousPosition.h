#ifndef PREVIOUSPOSITION
#define PREVIOUSPOSITION

#include <CommandBase.h>

class PreviousPosition: public CommandBase{
public:
    PreviousPosition();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
