#include "Robot.h"
#include <lib-4774/Functions.h>

#include <Commands/Move/MoveForward.h>

void Robot::RobotInit()
{
    CommandBase::init();
    lw = LiveWindow::GetInstance();
    ir = new AnalogInput(0);

    autonomousCommand = new MoveForward(2.0);
}

void Robot::DisabledPeriodic()
{
    Scheduler::GetInstance()->Run();
    PutDashboard();

    CommandBase::elevator->endSwitchTripped = false;
    CommandBase::elevator->readySwitchTopTripped = false;
    CommandBase::elevator->readySwitchBottomTripped = false;
    irTripped = false;

}

void Robot::AutonomousInit()
{
    if (autonomousCommand != NULL)
        autonomousCommand->Start();
}

void Robot::AutonomousPeriodic()
{
    Scheduler::GetInstance()->Run();
    PutDashboard();
}

void Robot::TeleopInit()
{
    // This makes sure that the autonomous stops running when
    // teleop starts running. If you want the autonomous to
    // continue until interrupted by another command, remove
    // this line or comment it out.
    if (autonomousCommand != NULL)
        autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic()
{
    Scheduler::GetInstance()->Run();
    PutDashboard();
    SmartDashboard::PutNumber("Encoder Cm: ", CommandBase::elevator->getEncoder());
}

void Robot::TestPeriodic()
{
    lw->Run();
}

void Robot::PutDashboard() {
    double chassis_encoders[4] = {};
    CommandBase::chassis->EncoderDistance(chassis_encoders);
    SmartDashboard::PutNumber("Encoder Motor A: ", chassis_encoders[0]);
    SmartDashboard::PutNumber("Encoder Motor B: ", chassis_encoders[1]);
    SmartDashboard::PutNumber("Encoder Motor C: ", chassis_encoders[2]);
    SmartDashboard::PutNumber("Encoder Motor D: ", chassis_encoders[3]);
    SmartDashboard::PutData(CommandBase::imu);

    SmartDashboard::PutNumber("RollDeg", lib4774::r2d(CommandBase::imu->GetRoll()));
    SmartDashboard::PutNumber("PitchDeg", lib4774::r2d(CommandBase::imu->GetPitch() ));
    SmartDashboard::PutNumber("YawDeg", lib4774::r2d(CommandBase::imu->GetYaw()));

    SmartDashboard::PutBoolean("End Switch Tripped", CommandBase::elevator->endSwitchTripped);
    SmartDashboard::PutBoolean("Ready Switch Top Tripped", CommandBase::elevator->readySwitchTopTripped);
    SmartDashboard::PutBoolean("Ready Switch Bottom Tripped", CommandBase::elevator->readySwitchBottomTripped);
    if(ir->GetValue() < 500) {
        irTripped = true;
    }
    SmartDashboard::PutBoolean("Ir Trippped: ", irTripped);
    SmartDashboard::PutNumber("Ir Sensor", ir->GetValue());
}


START_ROBOT_CLASS(Robot);

