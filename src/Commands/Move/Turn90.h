#ifndef TURN_90_H
#define TURN_90_H

#include <CommandBase.h>

class Turn90: public CommandBase
{
  public:
    enum directions {
        LEFT,
        RIGHT
    };
	Turn90(directions direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	directions direction;
};

#endif
