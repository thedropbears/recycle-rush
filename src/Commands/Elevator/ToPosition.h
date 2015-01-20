#ifndef TOPOSITION
#define TOPOSITION

#include <CommandBase.h>

class ToPosition: public CommandBase{
public:
    ToPosition();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
