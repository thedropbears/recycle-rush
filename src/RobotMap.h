#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

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

#define JOY_DRV_DEAD_X 0.05
#define JOY_DRV_DEAD_Y 0.05
#define JOY_DRV_DEAD_Z 0.25

#define GYRO_RESET_BUTTON 11

const int Strafe_Motor_Ratio = 0.33;

#endif
