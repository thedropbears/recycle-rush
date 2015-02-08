#ifndef BINTOTEAUTO
#define BINTOTEAUTO

// Pick up bin and tote and move them to the autonomous zone

#include <WPILib.h>

#define TO_TOTE 0.6 //meters

class BinToteAuto: public CommandGroup {
public:
    BinToteAuto();
};

#endif
