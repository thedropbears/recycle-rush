#ifndef INTAKETOTE
#define INTAKETOTE

#include <CommandBase.h>

class IntakeTote: public CommandBase{
public:
    IntakeTote();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
