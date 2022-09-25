
#include "WalkingEnemyActor.h"
#include <iostream>

WalkingEnemyActor::WalkingEnemyActor(float x, float y, float w, float h, float borderX, float borderX2) : ActiveActor(x, y, w, h) {
    this->posX = x;
    this->posY = y;
    this->width = width;
    this->height = height;
    this->xBorderLeft = borderX;
    this->xBorderRight = borderX2;
    //initialize velocity to 0 initially
    xVel = -0.2;
    yVel = 0;
    gravityDirection = 1;
    onGround = false;
    hitPoints = 3;
    weaponCooldown = 0;
    id = WALKING_ENEMY;
    //variables for detecting turnaround
    startingTimer = 0;
    turnBuffer = 0;
    //slightly random base timer so that they do not all fire at once
    weaponCooldown = WEAPON_BASE_COOLDOWN;
    int random = rand() % 1000;
    float randomFloat = (float) random;
    weaponCooldown -= randomFloat;
}

// angle should be passed in in degrees
const std::vector<std::shared_ptr<ActiveActor>> WalkingEnemyActor::fireWeapon(float angle){
    std::vector<std::shared_ptr<ActiveActor>> projectiles;
    float bulletVel = .35;
    std::shared_ptr<ProjectileActor> currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX + width / 2,posY + height / 2,32,32,
    ENEMY_PISTOL_PROJECTILE, bulletVel, true, xVel > 0,1));
    currProjectile->setxVel(std::cos(-1 * angle * 3.141592653 / 180) * bulletVel);
    currProjectile->setyVel(std::sin(-1 * angle * 3.141592653 / 180) * bulletVel);
    projectiles.push_back(currProjectile);
    return projectiles;
}

void WalkingEnemyActor::changeDirection(void){
    xVel = xVel * -1;
}

bool WalkingEnemyActor::canFire(){
    if (weaponCooldown <= 0){
        weaponCooldown = WEAPON_BASE_COOLDOWN;
        return true;
    }
    return false;
}

void WalkingEnemyActor::flip(void){
    onGround = false;
    gravityDirection *= -1;
}

//based on Sam's implementation from PlayerActor
//preliminary implementation...
void WalkingEnemyActor::move(unsigned long long delta){
    if (startingTimer <= 600){ //game needs time to be able to place enemy properly
        startingTimer += delta;
        yVel += baseGravity * gravityDirection * delta;
        posY += yVel * delta;
        return;
    }

    if ((getXPosition() <= xBorderLeft || getXPosition() >= xBorderRight) && turnBuffer >= 100){
        changeDirection();
        turnBuffer = 0;
    }
    else if (turnBuffer <= 100) turnBuffer += delta;

    posX += xVel * delta;
    yVel += baseGravity * gravityDirection * delta;
    posY += yVel * delta;
}


void WalkingEnemyActor::update(unsigned long long delta){
    move(delta);
    //update ability to fire
    if (weaponCooldown > (float) -1){
    weaponCooldown -= delta;
    }
}

