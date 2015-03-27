#include "GyroCorrection.h"

void GyroCorrection::PIDWrite(float output) {
    correction = output;
}
