#ifndef OI_H
#define OI_H

#include "WPILib.h"

#include "lib-4774/commands/InterruptTrigger.h"


class OI
{
private:
    InterruptTrigger* trigger;

public:
	OI();
};

#endif
