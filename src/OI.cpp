#include "OI.h"

#include "Commands/PID/GyroReset.h"
#include "lib-4774/Functions.h"

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
    //return applyDeadZone(JoyDrv->GetX(), JOY_DRV_DEAD_X);
    float scaled = lib4774::scaleJoystick(JoyDrv->GetX(), JOYSTICK_X_EXPONENTIAL, JOY_DRV_DEAD_X);
    SmartDashboard::PutNumber("Joystick X", scaled);
    return scaled;
}

double OI::getJoyDrvY(){
    //return applyDeadZone(JoyDrv->GetY(), JOY_DRV_DEAD_Y);
    float scaled = lib4774::scaleJoystick(JoyDrv->GetY(), JOYSTICK_Y_EXPONENTIAL, JOY_DRV_DEAD_Y);
    SmartDashboard::PutNumber("Joystick Y", scaled);
    return scaled;
}

double OI::getJoyDrvZ(){
    //return applyDeadZone(JoyDrv->GetZ(), JOY_DRV_DEAD_Z);
    float scaled = lib4774::scaleJoystick(JoyDrv->GetZ(), JOYSTICK_Z_EXPONENTIAL, JOY_DRV_DEAD_Z);
    SmartDashboard::PutNumber("Joystick Z", scaled);
    return scaled;
}

double OI::getJoyDrvThrottle(){
    //return (JoyDrv->GetThrottle()-1.0)/2.0;
    return JoyDrv -> GetThrottle();

}
