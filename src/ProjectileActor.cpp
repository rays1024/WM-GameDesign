//
// Created by xramz on 3/19/2022.
//

#include "ProjectileActor.h"


ProjectileActor::ProjectileActor(float x, float y, float w, float h, int id, float speed, bool verticalDir, bool horizontalDir, int gravityDirection) 
: ActiveActor(x, y, w, h) {
    this->posX = x;
    this->posY = y;
    this->width = w;
    this->height = h;
    direction = verticalDir;
    hDirection = horizontalDir;

    xVel = 0;
    yVel = 0;

    this->id = id;

    bulletVel = speed;

    hitPoints = 1;
    distTraveled = 0;
    this->gravityDirection = gravityDirection;
    onGround = false;
}

//doubles the projectile size
void ProjectileActor::changeSize(void){
    width *= 2;
    height *= 2;
}

void ProjectileActor::dealDamage(void){
    damage += 1;
}

void ProjectileActor::move(unsigned long long delta){
    posX += xVel * delta;
    if (id == ENEMY_LOBBING_PROJECTILE){
        yVel += gravityDirection * baseGravity * delta;
    }
    posY += yVel * delta;
    distTraveled += bulletVel * delta;
    if (distTraveled > 800 && id == PLAYER_PISTOL_PROJECTILE){
        hitPoints -= 1;
    }
    else if (distTraveled > 1200 && id == ENEMY_PISTOL_PROJECTILE){
        hitPoints -= 1;
    }
    else if (distTraveled > 300 && id == PLAYER_SPREAD_PROJECTILE){
        hitPoints -= 1;
    }
    else if (distTraveled > 1100 && id == ENEMY_LOBBING_PROJECTILE) {
        hitPoints -= 1;
    }
}

void ProjectileActor::update(unsigned long long delta){
    move(delta);
}