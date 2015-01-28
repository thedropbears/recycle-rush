#include "MoveToTote.h"
#include <RobotMap.h>
#include <CommandBase.h>



MoveToTote::MoveToTote()
{
	// Use Requires() here to declare subsystem dependencies
	// eg.Requires(chassis);
    Requires(chassis);
}

// Called just before this Command runs the first time
void MoveToTote::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void MoveToTote::Execute()
{
    chassis->Drive(0.8, 0.0, 0.0, 1.0, Strafe_Motor_Ratio);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveToTote::IsFinished()
{
	if (chassis->ReturnDistance() >= 60) {//cm
	    return true;
	}
	else {return false;}
}

// Called once after isFinished returns true
void MoveToTote::End()
{
    chassis->Drive(0.0,0.0,0.0,0.0, Strafe_Motor_Ratio);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveToTote::Interrupted()
{
    End();
}
