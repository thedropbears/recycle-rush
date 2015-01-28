#ifndef DRIVE_FORWARD_H
#define DRIVE_FORWARD_H

#include "CommandBase.h"
#include "WPILib.h"

class DriveForward: public CommandBase
{
  public:
	DriveForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
