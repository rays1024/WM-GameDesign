//
// Process to specifically represent the player
//

#ifndef CSCI437_ACTIVEPROCESS_H
#define CSCI437_ACTIVEPROCESS_H
#include "Process.h"
#include "PlayerActor.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

class ActiveProcess : public Process {
    
    protected:
        std::shared_ptr<ActiveActor> actor;

    public:
        ActiveProcess(int id);
        ActiveProcess(int id, std::shared_ptr<ActiveActor> actor);
        void update(unsigned long long deltaMs);
        const int& getActorId() const {return actor->getActorType();}
        std::shared_ptr<ActiveActor> getActor() const {return actor;}

};



#endif //CSCI437_ACTIVEPROCESS_H