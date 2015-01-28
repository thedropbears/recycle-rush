#include "DriveForward.h"
#include <RobotMap.h>
#include <CommandBase.h>



DriveForward::DriveForward()
{
	// Use Requires() here to declare subsystem dependencies
	// eg.Requires(chassis);
    Requires(chassis);
}

// Called just before this Command runs the first time
void DriveForward::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute()
{
    chassis->Drive(0.8, 0.0, 0.0, 1.0, Strafe_Motor_Ratio);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished()
{
	if (chassis->ReturnDistance() >= 397) {//cm
	    return true;
	}
	else {return false;}
}

// Called once after isFinished returns true
void DriveForward::End()
{
    chassis->Drive(0.0,0.0,0.0,0.0, Strafe_Motor_Ratio);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForward::Interrupted()
{
    End();
}
