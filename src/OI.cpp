#include "OI.h"

#include "lib-4774/commands/ReadMpu.h"

OI::OI()
{
    trigger = new InterruptTrigger();
    trigger->WhenActive(new ReadMpu());
}
