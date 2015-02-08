#ifndef TOGGLEPID
#define TOGGLEPID

#include <CommandBase.h>

class TogglePID: public CommandBase{
public:
    TogglePID();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
