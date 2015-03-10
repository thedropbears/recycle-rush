#ifndef OUTPUTTOTE
#define OUTPUTTOTE

#include <CommandBase.h>

class OutputTote: public CommandBase{
public:
    OutputTote();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
