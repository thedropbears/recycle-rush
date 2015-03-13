#include <Commands/Move/RotateOnSpot.h>

#include <lib-4774/Functions.h>

RotateOnSpot::RotateOnSpot(double angle)
{
	// Use Requires() here to declare subsystem dependencies
	// eg.Requires(chassis);
    Requires(chassis);
    this->angle = angle;
}

// Called just before this Command runs the first time
void RotateOnSpot::Initialize(){
	chassis->EnablePID();
}

// Called repeatedly when this Command is scheduled to run
void RotateOnSpot::Execute()
{
	if(!spinning) {
	    chassis->HeadingChange(lib4774::d2r(angle)); //spin one eighty!
	    spinning = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool RotateOnSpot::IsFinished()
{
    //will be done in PID when that is available, just a placeholder for now
    if(chassis->OnTarget())
        return true;
	return false;
}

// Called once after isFinished returns true
void RotateOnSpot::End()
{
    chassis->DisablePID();
    chassis->Drive(0,0,0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateOnSpot::Interrupted()
{
    End();
}
