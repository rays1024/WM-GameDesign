#ifndef CSCI437_PLAYERPROCESS_H
#define CSCI437_PLAYERPROCESS_H
#include "Actor.h"
#include "ActiveActor.h"
#include "PlayerActor.h"
#include "Process.h"

class PlayerProcess : public Process {

    protected:
    std::shared_ptr<PlayerActor> player;

    public:

    //pure virtual methods

    //each process type will initialize a class based on the passed ID
    virtual void update(unsigned long long deltaMs);

    PlayerProcess(int id);
    PlayerProcess(int id, const std::shared_ptr<PlayerActor> player);

    std::shared_ptr<PlayerActor> getPlayerActor() const {return player;}
};


#endif //CSCI437_PLAYERPROCESS_H