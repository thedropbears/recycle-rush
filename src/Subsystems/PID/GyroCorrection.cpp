#include "GyroCorrection.h"

void GyroCorrection::PIDWrite(float output) {
    if(correction >= 0.5) {
        correction = 0.5;
    } else {
        correction = output;
    }
}
