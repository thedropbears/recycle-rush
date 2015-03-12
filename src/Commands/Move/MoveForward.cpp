#include "MoveForward.h"

MoveForward :: MoveForward(double metersToMove): CommandBase ("MoveForward"){
    Requires(chassis);
    this->metersToMove = metersToMove;
}

void MoveForward::Initialize(){
    SmartDashboard::PutNumber("Running", 1);
    chassis->ZeroEncoders();
    if(metersToMove >= 0) {
        chassis->Drive(MOVE_FORWARD_SPEED, 0.0, 0.0, MOVE_FORWARD_SPEED);
    }
    else {
        chassis->Drive(-MOVE_FORWARD_SPEED, 0.0, 0.0, MOVE_FORWARD_SPEED);
    }
}

void MoveForward::Execute(){
}

bool MoveForward::IsFinished(){
    double distance[4] = {};
    chassis->EncoderDistance(distance);
    double average = 0;
    for(int i = 0; i<4; i++) {
        average += distance[i];
    }
    average = average/100.0;
    if(metersToMove >= 0) {
        if(average >= metersToMove) {

            return true;
        } else {
            return false;
        }
    } else {
        if(average <= metersToMove) {
            return true;
        } else {
            return false;
        }
    }
}

void MoveForward::End(){
    chassis->Stop();
}

void MoveForward::Interrupted(){
    End();
}
