#include <Commands/Auton/MoveForward.h>
#include <RobotMap.h>

MoveForward :: MoveForward(double metersToMove): CommandBase ("MoveForward"){
    Requires(chassis);
    this->metersToMove = metersToMove;
}

void MoveForward::Initialize(){
    chassis->ZeroEncoders();
}

void MoveForward::Execute(){
    chassis->Drive(0.5, 0.0, 0.0, MOVE_FORWARD_SPEED, Strafe_Motor_Ratio);
}

bool MoveForward::IsFinished(){
    distance = chassis->EncoderDistance();
    if(distance[1] >= metersToMove) {
        return true;
    } else {
        return false;
    }
}

void MoveForward::End(){
    chassis->Stop();
}

void MoveForward::Interrupted(){
}
