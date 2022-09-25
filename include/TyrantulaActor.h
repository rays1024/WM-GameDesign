//
//
//

#ifndef CSCI437_TYRANTULAACTOR_H
#define CSCI437_TYRANTULAACTOR_H

#include "ActiveActor.h"
#include "ProjectileActor.h"

class TyrantulaActor : public ActiveActor{
    public:
        TyrantulaActor(float x, float y, float w, float h);
        void move(unsigned long long delta);
        void update(unsigned long long delta);
        const std::vector<std::shared_ptr<ActiveActor>> fireWeapon(float angle);
        //tyrantula may always fire :)
        bool canFire() {return true;}
    private:
        int weaponCooldown;
};







#endif //CSCI437_TYRANTULAACTOR_H