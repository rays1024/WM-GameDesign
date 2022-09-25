//
// Logic Class representing spikes
//

#ifndef CSCI437_SPIKEACTOR_H
#define CSCI437_SPIKEACTOR_H

#include "InactiveActor.h"

class SpikeActor : public InactiveActor {
    public:
        SpikeActor(float x, float y, float width, float height, int dir);
        void update(unsigned long long delta);
};

#endif