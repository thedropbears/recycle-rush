#ifndef ROTATE_ON_SPOT
#define ROTATE_ON_SPOT

#include <CommandBase.h>

class RotateOnSpot: public CommandBase
{
public:
	RotateOnSpot(double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool spinning = false;
	double angle;
};

#endif
