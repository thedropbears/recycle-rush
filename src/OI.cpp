#include "OI.h"

#include <lib-4774/Functions.h>

#include <Commands/Elevator/ChangeState.h>
#include <Commands/Elevator/GoToElevatorPosition.h>
#include <Commands/Elevator/LowerElevator.h>
#include <Commands/Elevator/MoveElevatorToNextPosition.h>
#include <Commands/Elevator/MoveElevatorToPreviousPosition.h>
#include <Commands/Elevator/RaiseElevator.h>
#include <Commands/PID/ResetGyro.h>
#include <Commands/PID/ToggleFieldDrive.h>
#include <Commands/PID/TogglePID.h>
#include <Commands/Light/ToggleAtFrequency.h>
#include <Commands/Elevator/StopElevator.h>

#include <Subsystems/Move/Elevator.h>


OI::OI()
{
    JoyDrv = new Joystick(0);
    GameDrv = new Joystick(1);

    gyroResetButton = new JoystickButton (JoyDrv, GYRO_RESET_BUTTON);
    gyroResetButton->WhenPressed(new ResetGyro());

    fieldOrientButton = new JoystickButton (JoyDrv, FIELD_ORIENT_BUTTON);
    fieldOrientButton->WhenPressed(new ToggleFieldDrive());

    togglePIDButton = new JoystickButton (JoyDrv, TOGGLE_PID_BUTTON);
    togglePIDButton->WhenPressed(new TogglePID());

    elevatorUpButton = new JoystickButton (JoyDrv, RAISE_ELEVATOR_BUTTON);
    elevatorUpButton->WhileHeld(new RaiseElevator());

    elevatorDownButton = new JoystickButton (JoyDrv, LOWER_ELEVATOR_BUTTON);
    elevatorDownButton->WhileHeld(new LowerElevator());

    nextElevatorPositionButton = new JoystickButton (JoyDrv, MOVE_ELEVATOR_TO_NEXT_POSITION_BUTTON);
    nextElevatorPositionButton->ToggleWhenPressed(new MoveElevatorToNextPosition());

    previousElevatorPositionButton = new JoystickButton (JoyDrv, MOVE_ELEVATOR_TO_PREVIOUS_POSITION_BUTTON);
    previousElevatorPositionButton->ToggleWhenPressed(new MoveElevatorToPreviousPosition());

    stackButton = new JoystickButton (JoyDrv, STACK_BUTTON);
    stackButton->WhenPressed(new GoToElevatorPosition(Elevator::states::READYBIN));

    strobeButton = new JoystickButton (JoyDrv, STROBE_BUTTON);
    strobeButton->WhenPressed(new ToggleAtFrequency(STROBE_RATE));

    stopElevatorButton = new JoystickButton (JoyDrv, STOP_ELEVATOR_BUTTON);
    stopElevatorButton->WhileHeld(new StopElevator());

    gamepadElevatorUpButton = new JoystickButton (GameDrv, G_RAISE_ELEVATOR_BUTTON);
    gamepadElevatorUpButton->WhileHeld(new RaiseElevator());

    gamepadElevatorDownButton = new JoystickButton (GameDrv, G_LOWER_ELEVATOR_BUTTON);
    gamepadElevatorDownButton->WhileHeld(new LowerElevator());


    gamepadNextElevatorPositionButton = new JoystickButton (GameDrv, G_MOVE_ELEVATOR_TO_NEXT_POSITION_BUTTON);
    gamepadNextElevatorPositionButton->ToggleWhenPressed(new MoveElevatorToNextPosition());

    gamepadPreviousElevatorPositionButton = new JoystickButton (GameDrv, G_MOVE_ELEVATOR_TO_PREVIOUS_POSITION_BUTTON);
    gamepadPreviousElevatorPositionButton->ToggleWhenPressed(new MoveElevatorToPreviousPosition());

    gamepadStopElevatorButton = new JoystickButton (GameDrv, G_STOP_ELEVATOR_BUTTON);
    gamepadStopElevatorButton->WhileHeld(new StopElevator());

    gamepadStackButton = new JoystickButton (GameDrv, G_STACK_BUTTON);
    gamepadStackButton->WhenPressed(new GoToElevatorPosition(Elevator::states::READYBIN));
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
    if((scaled == 0) && (JoyDrv->GetY() == 0) && (JoyDrv->GetZ() == 0)) {
        scaled = GameDrv->GetRawAxis(GAMEPAD_AXIS_LEFT_STICK_X);
    }
    return scaled;
}

double OI::getJoyDrvY(){
    //return applyDeadZone(JoyDrv->GetY(), JOY_DRV_DEAD_Y);
    float scaled = lib4774::scaleJoystick(JoyDrv->GetY(), JOYSTICK_Y_EXPONENTIAL, JOY_DRV_DEAD_Y);
    SmartDashboard::PutNumber("Joystick Y", scaled);
    if(scaled == 0 && JoyDrv->GetX() == 0 && JoyDrv->GetZ() == 0) {
        scaled = GameDrv->GetRawAxis(GAMEPAD_AXIS_LEFT_STICK_Y);
    }
    return scaled;
}

double OI::getJoyDrvZ(){
    //return applyDeadZone(JoyDrv->GetZ(), JOY_DRV_DEAD_Z);
    float scaled = lib4774::scaleJoystick(JoyDrv->GetZ(), JOYSTICK_Z_EXPONENTIAL, JOY_DRV_DEAD_Z);
    SmartDashboard::PutNumber("Joystick Z", scaled);
    if(scaled == 0 && JoyDrv->GetX() == 0 && getJoyDrvY() == 0) {
        scaled = GameDrv->GetRawAxis(GAMEPAD_AXIS_RIGHT_STICK_X);
    }
    return scaled;
}

double OI::getJoyDrvThrottle(){
    if((JoyDrv->GetY() == 0) && (JoyDrv->GetY() == 0) && (JoyDrv->GetZ() == 0)) {
        return GAMEPAD_THROTTLE;
    }
    SmartDashboard::PutNumber("Raw Throttle: ", JoyDrv->GetThrottle());
    return (JoyDrv->GetThrottle()-1.0)/-2.0;
    //return (JoyDrv -> GetThrottle()+1);

}
