
#ifndef CSCI437_FLYINGENEMYACTOR_H
#define CSCI437_FLYINGENEMYACTOR_H

#include "ActiveActor.h"

class FlyingEnemyActor : public ActiveActor {
public:
    FlyingEnemyActor(float x, float y, float w, float h);
    void update(unsigned long long delta);
    void move(unsigned long long delta);
    bool canFire() {return false;}

private:
    float middleLine;

};


#endif //CSCI437_FLYINGENEMYACTOR_H
