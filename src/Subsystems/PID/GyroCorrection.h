#ifndef GYROCORRECTION
#define GYROCORRECTION

#include "WPILib.h"

class GyroCorrection: public PIDOutput
{
private:
public:
    void PIDWrite(float output);
    float correction = 0;
};

#endif
