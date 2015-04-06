#ifndef Robot_h
#define Robot_h

#include "WPILib.h"
#include "CommandBase.h"


class Robot: public IterativeRobot
{
private:
    Command *binToteAuto;
    Command *binAuto;
    Command *threeToteAuto;
    Command *moveToAutoZone;
    Command *toteAuto;
    Command *autonomousCommand;
    Command *resetGyro;
    Command *togglePID;
    Command *winchUpAuto;
    int disabledGyroResetCounter = -1000;
    LiveWindow *lw;
    AnalogInput *ir;
    bool irTripped = false;
    SendableChooser* autoChooser;

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
