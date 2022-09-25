//
// Class for Tyrantula legs
//

#ifndef CSCI437_LEGACTOR_H
#define CSCI437_LEGACTOR_H

#include "ActiveActor.h"

class LegActor : public ActiveActor {
    public:
        LegActor(float x, float y, float w, float h, float angle,int startingDirection, const std::shared_ptr<ActiveActor> second);
        void update(unsigned long long delta);
        void move(unsigned long long delta);
        bool canFire() {return false;}
    private:
        float initialAngle;
        std::shared_ptr<ActiveActor> secondPart;
};

#endif //CSCI437_LEGACTOR_H