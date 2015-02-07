#ifndef MOVEFORWARD
#define MOVEFORWARD

#include <CommandBase.h>

#define MOVE_FORWARD_SPEED 0.5

class MoveForward: public CommandBase{
public:
    MoveForward(double metersToMove);
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
private:
    double metersToMove;
};

#endif
