#include "Turn90.h"
#include <RobotMap.h>
#include <CommandBase.h>



Turn90::Turn90()
{
	// Use Requires() here to declare subsystem dependencies
	// eg.Requires(chassis);
    Requires(chassis);
}

// Called just before this Command runs the first time
void Turn90::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Turn90::Execute()
{
    chassis->Drive(0.8, 0.0, 0.8, 1.0, Strafe_Motor_Ratio);
}

// Make this return true when this Command no longer needs to run execute()
bool Turn90::IsFinished()
{//To be checked
	if (chassis->ReturnDistance() >= 25) {//cm
	    return true;
	}
	else {return false;}
}

// Called once after isFinished returns true
void Turn90::End()
{
    chassis->Drive(0.0,0.0,0.0,0.0, Strafe_Motor_Ratio);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Turn90::Interrupted()
{
    End();
}
