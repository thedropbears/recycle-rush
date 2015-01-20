#ifndef PICKNMOVE
#define PICKNMOVE

// Pick up bin and tote and move them to the autonomous zone

#include <WPILib.h>
#include <CommandBase.h>

class PickNMove: public CommandGroup {
public:
    PickNMove();
};

#endif
