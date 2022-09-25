//
// Actor to represent a projectile. E.g., a moving entity with 1 HP
//

#ifndef CSCI437_PROJECTILEACTOR_H
#define CSCI437_PROJECTILEACTOR_H

#include "ActiveActor.h"

class ProjectileActor : public ActiveActor {
protected:
    const int OFFSCREEN_BUFFER = 10;
    void move(unsigned long long delta) override;
    float distTraveled;
    float bulletVel;

public:
    ProjectileActor(float x, float y, float w, float h, int id, float speed, bool verticalDir, bool horizontalDir,int gravityDirection) ;
    void changeSize(void);
    void dealDamage(void);
    bool canFire() {return false;}
    int damage;
    void update(unsigned long long delta) override;
};


#endif //CSCI437_PROJECTILEACTOR_H