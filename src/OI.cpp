#include "OI.h"

#include "Commands/PID/GyroReset.h"
#include "lib-4774/Functions.h"
#include "Commands/Elevator/ElevatorUp.h"
#include "Commands/Elevator/ElevatorDown.h"
#include "Commands/Elevator/NextElevatorPosition.h"
#include "Commands/Elevator/PreviousElevatorPosition.h"
#include "Subsystems/Move/Elevator.h"
#include "Commands/Elevator/ToElevatorPosition.h"
#include "Commands/Elevator/ChangeState.h"
#include "Commands/PID/ToggleFieldDrive.h"


OI::OI()
{
    JoyDrv = new Joystick(0);

    gyroResetButton = new JoystickButton (JoyDrv, GYRO_RESET_BUTTON);
    gyroResetButton->WhenPressed(new GyroReset());

    fieldOrientButton = new JoystickButton (JoyDrv, FIELD_ORIENT_BUTTON);
    fieldOrientButton->WhenPressed(new ToggleFieldDrive());

    elevatorUpButton = new JoystickButton (JoyDrv, ELEVATOR_UP_BUTTON);
    elevatorUpButton->WhenPressed(new ElevatorUp());

    elevatorDownButton = new JoystickButton (JoyDrv, ELEVATOR_DOWN_BUTTON);
    elevatorDownButton->WhenPressed(new ElevatorDown());

    nextElevatorPositionButton = new JoystickButton (JoyDrv, NEXT_ELEVATOR_POSITION_BUTTON);
    nextElevatorPositionButton->WhenPressed(new NextElevatorPosition());

    previousElevatorPositionButton = new JoystickButton (JoyDrv, PREVIOUS_ELEVATOR_POSITION_BUTTON);
    previousElevatorPositionButton->WhenPressed(new PreviousElevatorPosition());

    stackButton = new JoystickButton (JoyDrv, STACK_BUTTON);
    stackButton->WhenPressed(new ToElevatorPosition(Elevator::states::READYBIN));


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
