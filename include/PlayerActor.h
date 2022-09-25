//
// Logic class representing the player
//

#ifndef CSCI437_PLAYERACTOR_H
#define CSCI437_PLAYERACTOR_H

#include "ActiveActor.h"
#include "PlatformActor.h"
#include "SpikeActor.h"
#include "ProjectileActor.h"
#include <vector>
#include <algorithm>
#include <limits>

class PlayerActor : public ActiveActor {
    public:

        PlayerActor(float x, float y, float width, float height);
        void flip(void);
        void move(unsigned long long delta);
        void leftRight(int direction);
        void jump(void);
        void update(unsigned long long delta);
        const std::vector<std::shared_ptr<ActiveActor>> fireWeapon(float angle);
        const bool& justJumped(void) const;
        void setCurWeapon(int weaponNum);
        void reset(void);
        void heal();
        const int& getCurrentWeapon(void) const {return curWeapon;}
        //not used for player
        bool canFire() {return 0;} 
        void setLaser(bool laser);
        const bool& getLaser(void) const {return laser;}

    private:
        unsigned long long flipTimer;
        bool jumped;
        float originX;
        float originY;
        int curWeapon;
        float weaponCooldown;
        bool laser;
};


#endif //CSCI437_PLAYERACTOR_H
