#include "WPILib.h"
#include "CommandBase.h"

#define _PI 3.14159

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	AnalogInput *ir;
	bool irTripped = false;

	void RobotInit()
	{
		CommandBase::init();
		lw = LiveWindow::GetInstance();
		ir = new AnalogInput(0);
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
		PutDashboard();

		CommandBase::elevator->endSwitchTripped = false;
		CommandBase::elevator->readySwitchTopTripped = false;
		CommandBase::elevator->readySwitchBottomTripped = false;
		irTripped = false;

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
		SmartDashboard::PutNumber("Encoder Cm: ", CommandBase::elevator->getEncoder());
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
	    SmartDashboard::PutBoolean("Ready Switch Bottom Tripped", CommandBase::elevator->readySwitchBottomTripped);
	    if(ir->GetValue() < 500) {
	        irTripped = true;
	    }
	    SmartDashboard::PutBoolean("Ir Trippped: ", irTripped);
	}
};

START_ROBOT_CLASS(Robot);

