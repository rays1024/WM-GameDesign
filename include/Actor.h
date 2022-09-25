//
// Abstract superclass defining any physical entity in the game world.
// Including the player, enemies, platforms, projectiles, etc.
//

#ifndef CSCI437_ACTOR_H
#define CSCI437_ACTOR_H
#include "constants.h"


class Actor {

protected:

    //all actors have a position, as well as a size
    float posX;
    float posY;

    //height meaning width on Y axis
    float height;
    float width;

    int id;
    //vertical and horizontal direction
    //true = up
    bool direction = true;
    //true = right
    bool hDirection = true;

public:

    const float& getYPosition() const {return posY;}
    const float& getXPosition() const {return posX;}
    const float& getHeight() const {return height;}
    const float& getWidth() const {return width;}
    void setXPosition(float x) {posX = x;}
    void setYPosition(float y) {posY = y;}
    const int getVerticalDirection() const {return direction;}
    const int getHorizontalDirection() const {return hDirection;}
    virtual void update(unsigned long long delta){};
    //each subclass should return some ID, but generic actor should never
    const int& getActorType(void) const {return id;}

    Actor(float x, float y, float width, float height) : posX(x), posY(y), width(width), height(height) {};

};


#endif //CSCI437_ACTOR_H
