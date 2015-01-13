#include "OI.h"

#include "lib-4774/commands/ReadMpu.h"
#include "Commands/PID/GyroReset.h"

OI::OI()
{
    joyDrv = new Joystick(1);

    trigger = new InterruptTrigger();
    trigger->WhenActive(new ReadMpu());

    gyroResetButton = new JoystickButton (joyDrv, GYRO_RESET_BUTTON);
    gyroResetButton->WhenPressed(new GyroReset());
}

Joystick* OI::getJoyDrv() {
    return joyDrv;
}
