#ifndef CSCI437_INACTIVEPROCESS_H
#define CSCI437_INACTIVEPROCESS_H
#include "Process.h"


class InactiveProcess : public Process{
    protected:

    std::shared_ptr<InactiveActor> actor;

    public:
    InactiveProcess(int id);
    InactiveProcess(int id, std::shared_ptr<InactiveActor> actor);
    void update(unsigned long long deltaMs);
    const int& getActorId() const {return actor->getActorType();}
    std::shared_ptr<InactiveActor> getActor() const{return actor;};    
};

#endif //CSCI437_INACTIVEPROCESS_H