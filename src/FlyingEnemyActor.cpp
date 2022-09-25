
#include "FlyingEnemyActor.h"


FlyingEnemyActor::FlyingEnemyActor(float x, float y, float w, float h) : ActiveActor(x, y, w, h) {
    this->posX = x;
    this->posY = y;
    this->width = width;
    this->height = height;
    //initialize velocity to 0 initially
    xVel = 0.18;
    yVel = 0;
    gravityDirection = 1;
    onGround = false;
    hitPoints = 3;
    id = FLYING_ENEMY;
    middleLine = y + 90;
}

//based on Sam's implementation from PlayerActor
//preliminary implementation...
void FlyingEnemyActor::move(unsigned long long delta){
    posX += xVel * delta;
    if (posY >= middleLine){
        gravityDirection = -1;
    }
    else{
        gravityDirection = 1;
    }
    yVel += 0.3 * baseGravity * gravityDirection * delta;
    posY += yVel * delta;
}

//need to account for collisions (with platforms/other actors)

void FlyingEnemyActor::update(unsigned long long delta){
    move(delta);
}
