#ifndef ResetGyro_H
#define ResetGyro_H

#include <CommandBase.h>

class GyroReset: public CommandBase {
    public:
        GyroReset();
        virtual void Initialize();
        virtual void Execute();
        virtual bool IsFinished();
        virtual void End();
        virtual void Interrupted();
};

#endif
