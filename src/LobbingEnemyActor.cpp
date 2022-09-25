
#include "LobbingEnemyActor.h"


LobbingEnemyActor::LobbingEnemyActor(float x, float y, float w, float h) : ActiveActor(x, y, w, h) {
    this->posX = x;
    this->posY = y;
    this->width = width;
    this->height = height;
    //initialize velocity to 0 initially
    xVel = 0;
    yVel = 0;
    weaponCooldown = 0;
    hitPoints = 3;
    gravityDirection = 1;
    hDirection = 0;
    id = LOBBING_ENEMY;
}

const std::vector<std::shared_ptr<ActiveActor>> LobbingEnemyActor::fireWeapon(float angle){
    if (std::abs((int) angle) < 90){
        hDirection = true;
    }
    else{
        hDirection = false;
    }
    std::vector<std::shared_ptr<ActiveActor>> projectiles;
    float bulletVel = .35;
    std::shared_ptr<ProjectileActor> currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX + width / 2,posY + height / 2,32,32,
    ENEMY_LOBBING_PROJECTILE,std::cos(-1 * angle * 3.141592653 / 180) * bulletVel, true, xVel > 0,gravityDirection));
    currProjectile->setxVel(std::cos(-1 * angle * 3.141592653 / 180) * bulletVel);
    currProjectile->setyVel(std::sin(-1 * angle * 3.141592653 / 180) * bulletVel * 4);
    projectiles.push_back(currProjectile);
    return projectiles;

}

void LobbingEnemyActor::changeDirection(void){
    xVel = xVel * -1;
}

bool LobbingEnemyActor::canFire(){
    if (weaponCooldown <= 0){
        weaponCooldown = WEAPON_BASE_COOLDOWN;
        return true;
    }
    return false;
}

void LobbingEnemyActor::move(unsigned long long delta){
    //enemy may jump, does not move horizontally though
    yVel += gravityDirection * baseGravity * delta;
    posY += yVel * delta;
    //sanity check so that it doesnt go too low
    if (weaponCooldown > (float) -1){
    weaponCooldown -= delta;
    }
}

//need to account for collisions (with platforms/other actors)

void LobbingEnemyActor::update(unsigned long long delta){
    move(delta);
}
