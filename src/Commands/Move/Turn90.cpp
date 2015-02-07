#include "Turn90.h"
#include <RobotMap.h>

Turn90::Turn90(directions direction)
{
	// Use Requires() here to declare subsystem dependencies
	// eg.Requires(chassis);
    this->direction = direction;
    Requires(chassis);
    Requires(imu);
}

// Called just before this Command runs the first time
void Turn90::Initialize(){
    imu->Zero();
}

// Called repeatedly when this Command is scheduled to run
void Turn90::Execute()
{
    chassis->Drive(0.0, 0.0, AUTON_TURN_Z, AUTON_TURN_THROTTLE);
}

// Make this return true when this Command no longer needs to run execute()
bool Turn90::IsFinished()
{
    //will be done in PID when that is available, just a placeholder for now
    if(imu->GetYaw() >= 90.0) {
        return true;
    } else {
        return false;
    }
}

// Called once after isFinished returns true
void Turn90::End()
{
    chassis->Drive(0.0,0.0,0.0,0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Turn90::Interrupted()
{
    End();
}
