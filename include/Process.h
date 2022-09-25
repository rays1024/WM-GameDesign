//
// Class describing the state of game objects for process managing
// Contains an actor, as well as an enum describing the state of the entity
//

#ifndef CSCI437_PROCESS_H
#define CSCI437_PROCESS_H
#include "Actor.h"
#include "ActiveActor.h"
#include <memory>
#include "constants.h"

class Process {

    protected:
    int state;

    public:

    //pure virtual methods

    //each process type will initialize a class based on the passed ID
    virtual void update(unsigned long long deltaMs) = 0;
    
    //trivial methods
    void pause() {state = PAUSED;}
    void unpause() {state = RUNNING;}
    const int& getState() const {return state;}
    void setState(int state){this->state = state;}
};


#endif //CSCI437_PROCESS_H
