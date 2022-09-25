//
// Logic Class representing platforms
//

#ifndef CSCI437_PLATFORMACTOR_H
#define CSCI437_PLATFORMACTOR_H

#include "InactiveActor.h"

class PlatformActor : public InactiveActor {
    public:
        PlatformActor(float x, float y, float width, float height);
        void update(unsigned long long delta);
};

#endif