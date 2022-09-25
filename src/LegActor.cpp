
#include "LegActor.h"

LegActor::LegActor(float x, float y, float w, float h, float angle,int startingDirection,const std::shared_ptr<ActiveActor> second) : ActiveActor(x, y, w, h) {
    this->posX = x;
    this->posY = y;
    this->width = w;
    this->height = h;
    hitPoints = 5;
    xVel = 0.1;
    yVel = 0;
    gravityDirection = 1;
    onGround = false;
    rotation = angle;
    rotationSpeed = startingDirection * -0.01;
    initialAngle = angle;
    secondPart = second;
    id = LEG;
}

void LegActor::move(unsigned long long delta){
    if (secondPart != NULL){
        posX += xVel * delta;
        if (rotation < initialAngle - 10){
            rotationSpeed *= -1;
            rotation = initialAngle - 10;
        }
        else if (rotation > initialAngle + 10){
            rotationSpeed *= -1;
            rotation = initialAngle + 10;
        }
        else{
            rotation += rotationSpeed * delta;
        }
        secondPart->setXPosition(height * std::sin((rotation) * 3.141592653 / 180) + posX);
        secondPart->setYPosition(height * std::cos((rotation) * 3.141592653 / 180) + posY);
    }
    else{
        if (rotation < initialAngle - 10){
            rotationSpeed *= -1;
            rotation = initialAngle - 10;
        }
        else if (rotation > initialAngle + 10){
            rotationSpeed *= -1;
            rotation = initialAngle + 10;
        }
        else{
            rotation += rotationSpeed * delta;
        }
    }
}

void LegActor::update(unsigned long long delta){
    move(delta);
}