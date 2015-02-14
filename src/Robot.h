#ifndef Robot_h
#define Robot_h

#include "WPILib.h"
#include "CommandBase.h"


class Robot: public IterativeRobot
{
private:
    Command *autonomousCommand;
    LiveWindow *lw;
    AnalogInput *ir;
    bool irTripped = false;

    void PutDashboard();

public:
    void RobotInit();
    void DisabledPeriodic();
    void AutonomousInit();
    void AutonomousPeriodic();
    void TeleopInit();
    void TeleopPeriodic();
    void TestPeriodic();
};

#endif
