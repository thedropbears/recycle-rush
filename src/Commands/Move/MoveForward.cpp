#include "MoveForward.h"

MoveForward :: MoveForward(double metersToMove): CommandBase ("MoveForward"){
    Requires(chassis);
    this->metersToMove = metersToMove;
}

void MoveForward::Initialize(){
    chassis->ZeroEncoders();
}

void MoveForward::Execute(){
    chassis->Drive(0.2, 0.0, 0.0, MOVE_FORWARD_SPEED);
}

bool MoveForward::IsFinished(){
    double distance[4] = {};
    chassis->EncoderDistance(distance);
    double average = 0;
    for(int i = 0; i<4; i++) {
        average += distance[i];
    }
    average /= 100.0;
    if(average >= metersToMove) {
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
