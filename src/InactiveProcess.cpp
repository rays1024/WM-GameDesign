#include "InactiveProcess.h"

InactiveProcess::InactiveProcess(int id){
    //currently not used
}

InactiveProcess::InactiveProcess(int id, std::shared_ptr<InactiveActor> actor){
    this->actor = actor;
    this->state = RUNNING;
}

void InactiveProcess::update(unsigned long long deltaMs){
    actor->update(deltaMs);
    if (!actor->getIsSolid()){
        state = DESTROYED;
    }
}