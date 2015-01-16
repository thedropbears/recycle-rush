#include "OI.h"

#include "Commands/PID/GyroReset.h"

OI::OI()
{
    JoyDrv = new Joystick(0);

    gyroResetButton = new JoystickButton (JoyDrv, GYRO_RESET_BUTTON);
    gyroResetButton->WhenPressed(new GyroReset());
}

Joystick* OI::getJoyDrv() {
    return JoyDrv;
}

double OI :: applyDeadZone(double input, double deadZone){
    if(input <= - deadZone || input >= deadZone){
        return input;
    }
    return 0.0;
}

double OI::getJoyDrvX(){
    return applyDeadZone(JoyDrv->GetX(), JOY_DRV_DEAD_X);
}

double OI::getJoyDrvY(){
    return applyDeadZone(JoyDrv->GetY(), JOY_DRV_DEAD_Y);
}

double OI::getJoyDrvZ(){
    return applyDeadZone(JoyDrv->GetZ(), JOY_DRV_DEAD_Z);
}

double OI::getJoyDrvThrottle(){
    //return (JoyDrv->GetThrottle()-1.0)/2.0;
    return JoyDrv -> GetThrottle();

}
