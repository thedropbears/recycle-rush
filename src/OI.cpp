#include "OI.h"

#include "Commands/PID/GyroReset.h"

OI::OI()
{
    joyDrv = new Joystick(0);

    gyroResetButton = new JoystickButton (joyDrv, GYRO_RESET_BUTTON);
    gyroResetButton->WhenPressed(new GyroReset());
}

Joystick* OI::getJoyDrv() {
    return joyDrv;
}
