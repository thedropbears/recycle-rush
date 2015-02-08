#include "MoveForward.h"

MoveForward :: MoveForward(double metersToMove): CommandBase ("MoveForward"){
    Requires(chassis);
    this->metersToMove = metersToMove;
}

void MoveForward::Initialize(){
    chassis->ZeroEncoders();
}

void MoveForward::Execute(){
    chassis->Drive(1.0, 0.0, 0.0, MOVE_FORWARD_SPEED);
}

bool MoveForward::IsFinished(){
    double distance[4] = {};
    chassis->EncoderDistance(distance);
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
    End();
}
