#ifndef MOVE_TO_TOTE_H
#define MOVE_TO_TOTE_H

#include "CommandBase.h"
#include "WPILib.h"

class MoveToTote: public CommandBase
{
  public:
	MoveToTote();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
