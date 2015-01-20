#ifndef PUSHBOT
#define PUSHBOT

#include <CommandBase.h>

class PushBot: public CommandBase{
public:
    PushBot();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
