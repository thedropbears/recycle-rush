#ifndef NEXTPOSITION
#define NEXTPOSITION

#include <CommandBase.h>

class NextPosition: public CommandBase{
public:
    NextPosition();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
