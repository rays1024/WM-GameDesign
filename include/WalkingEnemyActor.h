//
// Walking enemy logic class
//

#ifndef CSCI437_WALKINGENEMYACTOR_H
#define CSCI437_WALKINGENEMYACTOR_H
#include "ActiveActor.h"
#include "ProjectileActor.h"

class WalkingEnemyActor : public ActiveActor {
public:
    //x should be greater than borderX1, less than borderX2. otherwise they get stuck
    WalkingEnemyActor(float x, float y, float w, float h, float borderX1, float borderX2);
    void changeDirection(void);
    void flip(void);
    void move(unsigned long long delta);
    void update(unsigned long long delta);
    const std::vector<std::shared_ptr<ActiveActor>> fireWeapon(float angle);
    bool canFire();

private:
    //bool canShoot
    const float WEAPON_BASE_COOLDOWN = 3000;
    float weaponCooldown;
    unsigned long long startingTimer;
    //need a buffer so that walking enemy does not get stuck turning
    unsigned long long turnBuffer;
    float xBorderLeft, xBorderRight;
};


#endif //CSCI437_WALKINGENEMYACTOR_H
