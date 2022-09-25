//
// Logic class for the lobbing enemy

#ifndef CSCI437_LOBBINGENEMYACTOR_H
#define CSCI437_LOBBINGENEMYACTOR_H

#include "ActiveActor.h"
#include "ProjectileActor.h"

class LobbingEnemyActor : public ActiveActor {
    public:
        LobbingEnemyActor(float x, float y, float w, float h);
        const std::vector<std::shared_ptr<ActiveActor>> fireWeapon(float angle);
        void changeDirection(void);
        void move(unsigned long long delta);
        void update(unsigned long long delta);
        bool canFire();

    private:
        float weaponCooldown;
        float WEAPON_BASE_COOLDOWN = 1500;
};


#endif //CSCI437_LOBBINGENEMYACTOR_H
