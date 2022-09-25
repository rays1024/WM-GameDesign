
#include "TyrantulaActor.h"

TyrantulaActor::TyrantulaActor(float x, float y, float w, float h) : ActiveActor(x, y, w, h){
    posX = x;
    posY = y;
    width = w;
    height = h;

    xVel = 0.1;
    yVel = 0;

    hitPoints = 90;

    id = TYRANTULA;
}

void TyrantulaActor::move(unsigned long long delta){
    posX += xVel * delta;
}

void TyrantulaActor::update(unsigned long long delta){
    move(delta);
}

const std::vector<std::shared_ptr<ActiveActor>> TyrantulaActor::fireWeapon(float angle){
        //wall of bullets
        if (angle == 361){
            //wall attack
            std::vector<std::shared_ptr<ActiveActor>> projectiles;
            float bulletVel = .35;
            std::shared_ptr<ProjectileActor> currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX + width / 2,posY + 2 * height,32,32,
            ENEMY_PISTOL_PROJECTILE, bulletVel, true, xVel > 0,1));
            currProjectile->setxVel(bulletVel);
            projectiles.push_back(currProjectile);
            for (int i = 1; i < 21; i++){
                currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX + width / 2,posY + 2 * height - 40 * i,32,32,
                ENEMY_PISTOL_PROJECTILE, bulletVel, true, xVel > 0,1));
                currProjectile->setxVel(bulletVel);
                projectiles.push_back(currProjectile);
            }
            return projectiles;
        }

        else if (angle == 362){
            //floor lobbing            
            std::vector<std::shared_ptr<ActiveActor>> projectiles;
            float bulletVel = .35;
            std::shared_ptr<ProjectileActor> currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX + width / 2,posY + height / 2,32,32,
            ENEMY_LOBBING_PROJECTILE, std::cos(-1 * 2 * 3.141592653 / 180) * bulletVel, true, xVel > 0,1));
            currProjectile->setxVel(std::cos(-1 * 2 * 3.141592653 / 180) * bulletVel);
            currProjectile->setyVel(std::sin(-1 * 2 * 3.141592653 / 180) * bulletVel * 4);
            projectiles.push_back(currProjectile);
            return projectiles;
        }
        else if (angle == 363){
            //ceiling lobbing
            std::vector<std::shared_ptr<ActiveActor>> projectiles;
            float bulletVel = .35;
            std::shared_ptr<ProjectileActor> currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX + width / 2,posY + height / 2,32,32,
            ENEMY_LOBBING_PROJECTILE, std::cos(-1 * -2 * 3.141592653 / 180) * bulletVel, true, xVel > 0,-1));
            currProjectile->setxVel(std::cos(-1 * -2 * 3.141592653 / 180) * bulletVel);
            currProjectile->setyVel(std::sin(-1 * -2 * 3.141592653 / 180) * bulletVel * 4);
            projectiles.push_back(currProjectile);
            return projectiles;
        }
        else if (angle == 364){
            //spread shot
            //5 at a time
            std::vector<std::shared_ptr<ActiveActor>> projectiles;
            float bulletVel = .35;
            std::shared_ptr<ProjectileActor> currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX + width / 2,posY + height / 2,32,32,ENEMY_PISTOL_PROJECTILE,bulletVel, true, false,gravityDirection));
            currProjectile->setxVel(std::cos(30 * 3.141592653 / 180) * bulletVel);
            currProjectile->setyVel(std::sin(30 * 3.141592653 / 180) * bulletVel);
            projectiles.push_back(currProjectile);
            currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX + width / 2,posY + height / 2,32,32,ENEMY_PISTOL_PROJECTILE,bulletVel, true, false,gravityDirection));
            currProjectile->setxVel(std::cos(15 * 3.141592653 / 180) * bulletVel);
            currProjectile->setyVel(std::sin(15 * 3.141592653 / 180) * bulletVel);
            projectiles.push_back(currProjectile);
            currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX + width / 2,posY + height / 2,32,32,ENEMY_PISTOL_PROJECTILE,bulletVel, true, false,gravityDirection));
            currProjectile->setxVel(std::cos(0 * 3.141592653 / 180) * bulletVel);
            currProjectile->setyVel(std::sin(0 * 3.141592653 / 180) * bulletVel);
            projectiles.push_back(currProjectile);
            currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX + width / 2,posY + height / 2,32,32,ENEMY_PISTOL_PROJECTILE,bulletVel, true, false,gravityDirection));
            currProjectile->setxVel(std::cos(-15 * 3.141592653 / 180) * bulletVel);
            currProjectile->setyVel(std::sin(-15 * 3.141592653 / 180) * bulletVel);
            projectiles.push_back(currProjectile);
            currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX + width / 2,posY + height / 2,32,32,ENEMY_PISTOL_PROJECTILE,bulletVel, true, false,gravityDirection));
            currProjectile->setxVel(std::cos(-30 * 3.141592653 / 180) * bulletVel);
            currProjectile->setyVel(std::sin(-30 * 3.141592653 / 180) * bulletVel);
            projectiles.push_back(currProjectile);
            return projectiles;
        }
        else{
            //normal attack at given angle
            std::vector<std::shared_ptr<ActiveActor>> projectiles;
            float bulletVel = .60;
            std::shared_ptr<ProjectileActor> currProjectile = std::shared_ptr<ProjectileActor>(new ProjectileActor(posX + width / 2,posY + height / 2,32,32,
            ENEMY_PISTOL_PROJECTILE, bulletVel, true, xVel > 0,1));
            currProjectile->setxVel(std::cos(-1 * angle * 3.141592653 / 180) * bulletVel);
            currProjectile->setyVel(std::sin(-1 * angle * 3.141592653 / 180) * bulletVel);
            projectiles.push_back(currProjectile);
            return projectiles;
        }
    }