#include "ActiveProcess.h"


ActiveProcess::ActiveProcess(int id){
    
}

ActiveProcess::ActiveProcess(int id, std::shared_ptr<ActiveActor> actor){
    this->actor = actor;
    state = RUNNING;
}

void ActiveProcess::update(unsigned long long deltaMs){
    actor->update(deltaMs);
    if (actor->getHitPoints() <= 0){
        state = DESTROYED;
    }
}