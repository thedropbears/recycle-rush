#ifndef OMNIDRIVE_H
#define OMNIDRIVE_H

#include "CommandBase.h"
#include "WPILib.h"

class OmniDrive: public CommandBase
{
  public:
	OmniDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
