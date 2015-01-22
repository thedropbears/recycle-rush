#include "WPILib.h"
#include "CommandBase.h"

#define _PI 3.14159

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;

	void RobotInit()
	{
		CommandBase::init();
		lw = LiveWindow::GetInstance();
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
		PutDashboard();

		CommandBase::elevator->binSwitchTripped = false;
		CommandBase::elevator->endSwitchTripped = false;
		CommandBase::elevator->readySwitchTopTripped = false;
		CommandBase::elevator->readySwitchBottomTripped = false;
	}

	void AutonomousInit()
	{
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
		PutDashboard();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
		PutDashboard();
	}

	void TestPeriodic()
	{
		lw->Run();
	}

	void PutDashboard() {
	    SmartDashboard::PutData(CommandBase::imu);

	    SmartDashboard::PutNumber("RollDeg", (CommandBase::imu->GetRoll() * 180/_PI));
	    SmartDashboard::PutNumber("PitchDeg", (CommandBase::imu->GetPitch() * 180/_PI));
	    SmartDashboard::PutNumber("YawDeg", (CommandBase::imu->GetYaw() * 180/_PI));

	    SmartDashboard::PutBoolean("End Switch Tripped", CommandBase::elevator->endSwitchTripped);
	    SmartDashboard::PutBoolean("Ready Switch Top Tripped", CommandBase::elevator->readySwitchTopTripped);
	    SmartDashboard::PutBoolean("Bin Switch Tripped", CommandBase::elevator->binSwitchTripped);
	    SmartDashboard::PutBoolean("Ready Switch Bottom Tripped", CommandBase::elevator->readySwitchBottomTripped);
	}
};

START_ROBOT_CLASS(Robot);

