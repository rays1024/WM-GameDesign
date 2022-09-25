//
// Class to represent health and level end pickups
//

#ifndef CSCI437_PICKUPACTOR_H
#define CSCI437_PICKUPACTOR_H

#include "InactiveActor.h"

class PickupActor : public InactiveActor {
public:
    PickupActor(float x, float y, float w, float h, bool flip);
    void update(unsigned long long delta);
    //use setIsSolid for "picking up", process manager will detect

    void setPickupType(int id);

};


#endif //CSCI437_PICKUPACTOR_H
