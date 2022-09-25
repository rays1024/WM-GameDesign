//
// Subclass for any nonmoving entity
//

#ifndef CSCI437_INACTIVEACTOR_H
#define CSCI437_INACTIVEACTOR_H

#include "Actor.h"

class InactiveActor : public Actor{

protected:
    bool doesDamage;
    bool isSolid;

public:
    InactiveActor(float x, float y, float width, float height) : Actor(x, y, width, height){};
    virtual void update(unsigned long long delta){};

    //set methods
    void setDoesDamage(bool x);
    void setIsSolid(bool y);

    //get methods
    const bool& getDoesDamage() const;
    const bool& getIsSolid() const;
};


#endif //CSCI437_INACTIVEACTOR_H
