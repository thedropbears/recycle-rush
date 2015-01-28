#ifndef TURN_90_H
#define TURN_90_H

#include "CommandBase.h"
#include "WPILib.h"

class Turn90: public CommandBase
{
  public:
	Turn90();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
