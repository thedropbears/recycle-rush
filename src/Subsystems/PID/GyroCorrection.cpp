#include "GyroCorrection.h"
#include "../../RobotMap.h"

void GyroCorrection::PIDWrite(float output) {

    correction = output;
}
