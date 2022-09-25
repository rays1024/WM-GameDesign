//
//
//

#include "PlayerActor.h"
#include <iostream>

//set up player object
PlayerActor::PlayerActor(float x, float y, float width, float height) : ActiveActor(x, y, width, height){
    this->width = width;
    this->height = height;
    originX = x;
    originY = y;
    id = PLAYER;
    curWeapon = 1;
    reset();
    //timer for flip cooldown
    flipTimer = 0;
    laser = false;
}

void PlayerActor::update(unsigned long long delta){
    move(delta);
    if (flipTimer < 100){
    flipTimer += delta;
    }
}

//called every tick
//updates the player x and y position based on their velocity and gravity
void PlayerActor::move(unsigned long long delta){
    posX += xVel * delta;
    //makes gravity stronger if the player is falling
    if (gravityDirection > 0 && yVel < 0){
        yVel += baseGravity * gravityDirection * delta;
    }
    else if (gravityDirection > 0 && yVel >= 0){
        yVel += 1.85 * baseGravity * gravityDirection * delta;
    }
    else if (gravityDirection < 0 && yVel > 0){
        yVel += baseGravity * gravityDirection * delta;
    }
    else if (gravityDirection < 0 && yVel <= 0){
        yVel += 1.85 * baseGravity * gravityDirection * delta;
    }
    posY += yVel * delta;
    if (isInvincible){
        iFrames -= delta;
        if (iFrames <= 0){
            isInvincible = false;
        }
    }
    weaponCooldown -= delta;
}

//if the player is on the ground
//allows the player to jump
void PlayerActor::jump(void){
    if(onGround){
        onGround = false;
        jumped = true;
        if (baseGravity * gravityDirection > 0){
            yVel = -1.3;
        }
        if (baseGravity * gravityDirection < 0){
            yVel = 1.3;
        }
    }
    else{
        jumped = false;
    }
}

//inverts player gravity
void PlayerActor::flip(void){
    if (flipTimer >= 100){
    gravityDirection *= -1;
    onGround = false;
    flipTimer = 0;
    }
}

//sets the player x velocity depending
//on which direction is pressed
//and stops for no direction
void PlayerActor::leftRight(int direction){
    if (direction == -1){
        xVel = -0.4;
        facingLeft = true;
    }
    else if (direction == 1){
        xVel = 0.4;
        facingLeft = false;
    }
    else if (direction == 2){
        facingLeft = false;
    }
    else if (direction == -2){
        facingLeft = true;
    }
    else {
        xVel = 0;
    }
}

//projectile weapon
const std::vector<std::shared_ptr<ActiveActor>> PlayerActor::fireWeapon(float angle){
    if (weaponCooldown <= 0){
        std::vector<std::shared_ptr<ActiveActor>> projectiles;
        float bulletVel;
        if (curWeapon == 1){
            bulletVel = 0.9;
            if (!laser){
                weaponCooldown = 400;
            }
            if (facingLeft && gravityDirection > 0){
                std::shared_ptr<ProjectileActor> currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX - 15,posY+22,32,32,
                    PLAYER_PISTOL_PROJECTILE,bulletVel, true, false,gravityDirection));
                currProjectile->setxVel(std::cos((angle + 360) * 3.141592653 / 180) * bulletVel);
                currProjectile->setyVel(std::sin((angle + 360) * 3.141592653 / 180) * bulletVel);
                projectiles.push_back(currProjectile);
            }
            else if (facingLeft && gravityDirection < 0){
                std::shared_ptr<ProjectileActor> currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX - 15,posY+45,32,32,
                    PLAYER_PISTOL_PROJECTILE,bulletVel, false, false,gravityDirection));
                currProjectile->setxVel(std::cos((angle + 360) * 3.141592653 / 180) * bulletVel);
                currProjectile->setyVel(std::sin((angle + 360) * 3.141592653 / 180) * bulletVel);
                projectiles.push_back(currProjectile);
            }
            else if (!facingLeft && gravityDirection > 0){
                std::shared_ptr<ProjectileActor> currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX + width,posY+22,32,32,
                    PLAYER_PISTOL_PROJECTILE,bulletVel, false, true,gravityDirection));
                currProjectile->setxVel(std::cos(angle * 3.141592653 / 180) * bulletVel);
                currProjectile->setyVel(std::sin(angle * 3.141592653 / 180) * bulletVel);
                projectiles.push_back(currProjectile);
            }
            else if (!facingLeft && gravityDirection < 0){
                std::shared_ptr<ProjectileActor> currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX + width,posY+45,32,32,
                    PLAYER_PISTOL_PROJECTILE, bulletVel, true, true,gravityDirection));
                currProjectile->setxVel(std::cos(angle * 3.141592653 / 180) * bulletVel);
                currProjectile->setyVel(std::sin(angle * 3.141592653 / 180) * bulletVel);
                projectiles.push_back(currProjectile);
            }
        }
        if (curWeapon == 2){
            bulletVel = 0.5;
            if (!laser){
                weaponCooldown = 550;
            }
            if (facingLeft && gravityDirection > 0){
                std::shared_ptr<ProjectileActor> currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX - 15,posY+22,32,32,PLAYER_SPREAD_PROJECTILE,bulletVel, true, false,gravityDirection));
                currProjectile->setxVel(std::cos((angle + 360 + 15) * 3.141592653 / 180) * bulletVel);
                currProjectile->setyVel(std::sin((angle + 360 + 15) * 3.141592653 / 180) * bulletVel);
                projectiles.push_back(currProjectile);
                currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX - 15,posY+22,32,32,PLAYER_SPREAD_PROJECTILE,bulletVel, true, false,gravityDirection));
                currProjectile->setxVel(std::cos((angle + 360) * 3.141592653 / 180) * bulletVel);
                currProjectile->setyVel(std::sin((angle + 360) * 3.141592653 / 180) * bulletVel);
                projectiles.push_back(currProjectile);
                currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX - 15,posY+22,32,32,PLAYER_SPREAD_PROJECTILE,bulletVel, true, false,gravityDirection));
                currProjectile->setxVel(std::cos((angle + 360 - 15) * 3.141592653 / 180) * bulletVel);
                currProjectile->setyVel(std::sin((angle + 360 - 15) * 3.141592653 / 180) * bulletVel);
                projectiles.push_back(currProjectile);
            }
            else if (facingLeft && gravityDirection < 0){
                std::shared_ptr<ProjectileActor> currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX - 15,posY+45,32,32,PLAYER_SPREAD_PROJECTILE,bulletVel, false, false,gravityDirection));
                currProjectile->setxVel(std::cos((angle + 360 + 15) * 3.141592653 / 180) * bulletVel);
                currProjectile->setyVel(std::sin((angle + 360 + 15) * 3.141592653 / 180) * bulletVel);
                projectiles.push_back(currProjectile);
                currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX - 15,posY+45,32,32,PLAYER_SPREAD_PROJECTILE,bulletVel, false, false,gravityDirection));
                currProjectile->setxVel(std::cos((angle + 360) * 3.141592653 / 180) * bulletVel);
                currProjectile->setyVel(std::sin((angle + 360) * 3.141592653 / 180) * bulletVel);
                projectiles.push_back(currProjectile);
                currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX - 15,posY+45,32,32,PLAYER_SPREAD_PROJECTILE,bulletVel, false, false,gravityDirection));
                currProjectile->setxVel(std::cos((angle + 360 - 15) * 3.141592653 / 180) * bulletVel);
                currProjectile->setyVel(std::sin((angle + 360 - 15) * 3.141592653 / 180) * bulletVel);
                projectiles.push_back(currProjectile);
            }
            else if (!facingLeft && gravityDirection > 0){
                std::shared_ptr<ProjectileActor> currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX + width,posY+22,32,32,PLAYER_SPREAD_PROJECTILE,bulletVel, false, true,gravityDirection));
                currProjectile->setxVel(std::cos((angle + 15) * 3.141592653 / 180) * bulletVel);
                currProjectile->setyVel(std::sin((angle + 15) * 3.141592653 / 180) * bulletVel);
                projectiles.push_back(currProjectile);
                currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX + width,posY+22,32,32,PLAYER_SPREAD_PROJECTILE,bulletVel, false, true,gravityDirection));
                currProjectile->setxVel(std::cos((angle) * 3.141592653 / 180) * bulletVel);
                currProjectile->setyVel(std::sin((angle) * 3.141592653 / 180) * bulletVel);
                projectiles.push_back(currProjectile);
                currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX + width,posY+22,32,32,PLAYER_SPREAD_PROJECTILE,bulletVel, false, true,gravityDirection));
                currProjectile->setxVel(std::cos((angle - 15) * 3.141592653 / 180) * bulletVel);
                currProjectile->setyVel(std::sin((angle - 15) * 3.141592653 / 180) * bulletVel);
                projectiles.push_back(currProjectile);
            }
            else if (!facingLeft && gravityDirection < 0){
                std::shared_ptr<ProjectileActor> currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX + width,posY+45,32,32,PLAYER_SPREAD_PROJECTILE,bulletVel, true, true,gravityDirection));
                currProjectile->setxVel(std::cos((angle + 15) * 3.141592653 / 180) * bulletVel);
                currProjectile->setyVel(std::sin((angle + 15) * 3.141592653 / 180) * bulletVel);
                projectiles.push_back(currProjectile);
                currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX + width,posY+45,32,32,PLAYER_SPREAD_PROJECTILE,bulletVel, true, true,gravityDirection));
                currProjectile->setxVel(std::cos((angle) * 3.141592653 / 180) * bulletVel);
                currProjectile->setyVel(std::sin((angle) * 3.141592653 / 180) * bulletVel);
                projectiles.push_back(currProjectile);
                currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX + width,posY+45,32,32,PLAYER_SPREAD_PROJECTILE,bulletVel, true, true,gravityDirection));
                currProjectile->setxVel(std::cos((angle - 15) * 3.141592653 / 180) * bulletVel);
                currProjectile->setyVel(std::sin((angle - 15) * 3.141592653 / 180) * bulletVel);
                projectiles.push_back(currProjectile);
            }
        }
        return projectiles;
    }
    else{
        return {};
    }
}

const bool& PlayerActor::justJumped(void) const{
    return jumped;
}

void PlayerActor::setCurWeapon(int weaponNum){
    curWeapon = weaponNum;
}

void PlayerActor::reset(void){
    this->posX = originX;
    this->posY = originY;
    xVel = 0;
    yVel = 0;
    onGround = false;
    gravityDirection = 1;
    jumped = false;
    iFrames = 0;
    isInvincible = false;
    hitPoints = 3;
    facingLeft = false;
    weaponCooldown = 0;
}

void PlayerActor::heal(){
    if(getHitPoints() < 3) setHitPoints(getHitPoints()+1);
}

void PlayerActor::setLaser(bool laser){
    this->laser = laser;
}