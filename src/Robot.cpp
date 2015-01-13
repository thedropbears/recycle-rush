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
	}
};

START_ROBOT_CLASS(Robot);

