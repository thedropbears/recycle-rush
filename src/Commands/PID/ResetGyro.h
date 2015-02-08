#ifndef ResetGyro_H
#define ResetGyro_H

#include <CommandBase.h>

class ResetGyro: public CommandBase {
    public:
        ResetGyro();
        virtual void Initialize();
        virtual void Execute();
        virtual bool IsFinished();
        virtual void End();
        virtual void Interrupted();
};

#endif
