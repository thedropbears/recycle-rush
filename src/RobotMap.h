#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include "math.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

#define DRIVE_MOTOR_A_ID 1
#define DRIVE_MOTOR_B_ID 2
#define DRIVE_MOTOR_C_ID 3
#define DRIVE_MOTOR_D_ID 4
#define DRIVE_MOTOR_E_ID 5
#define DRIVE_MOTOR_F_ID 6

#define WINCH_TALON_CAN_ID 7

#define JOY_DRV_DEAD_X 0.05
#define JOY_DRV_DEAD_Y 0.05
#define JOY_DRV_DEAD_Z 0.25

#define JOYSTICK_X_EXPONENTIAL 10
#define JOYSTICK_Y_EXPONENTIAL 10
#define JOYSTICK_Z_EXPONENTIAL 40

#define GYRO_RESET_BUTTON 11
#define FIELD_ORIENT_BUTTON 12
#define ELEVATOR_UP_BUTTON 6
#define ELEVATOR_DOWN_BUTTON 4
#define NEXT_ELEVATOR_POSITION_BUTTON 5
#define PREVIOUS_ELEVATOR_POSITION_BUTTON 3
#define STACK_BUTTON 7

const double Strafe_Motor_Ratio = 0.33;

#define TO_SCORING_ZONE 10 // meters
#define AUTON_TURN_THROTTLE 0.4
#define AUTON_TURN_Z 1.0

#define READY_CHANNEL_BOTTOM 1
#define READY_CHANNEL_TOP 2
#define END_CHANNEL 3

#define WINCH_MOTOR_SPEED 1.0

#define ELEVATOR_DIO_TIMEOUT 5

#define rad2deg(x) ((x)/M_PI*180.0)
#define deg2rad(x) ((x)*M_PI/180.0)

#endif
