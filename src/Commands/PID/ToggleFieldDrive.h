#ifndef TOGGLEFIELDDRIVE
#define TOGGLEFIELDDRIVE

#include <CommandBase.h>

class ToggleFieldDrive: public CommandBase{
public:
    ToggleFieldDrive();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
