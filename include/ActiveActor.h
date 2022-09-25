//
// Describes any actor that moves within the game world,
// requiring an implementation of a move() method
//

#ifndef CSCI437_ACTIVEACTOR_H
#define CSCI437_ACTIVEACTOR_H
#include "Actor.h"
#include "PlatformActor.h"
#include "SpikeActor.h"
#include "InactiveActor.h"
#include <vector>
#include <algorithm>
#include <limits>
#include <memory>
#include <cmath>


class ActiveActor : public Actor {

protected:
    //store current velocity
    float xVel;
    float yVel;
    //store the absolute acceleration of gravity
    const float baseGravity = 0.003;
    std::vector<std::vector<float>> potentialPoints;
    std::vector<std::shared_ptr<Actor>> potentialCollisions;
    int gravityDirection;
    bool onGround;
    int hitPoints;
    float iFrames;
    bool isInvincible;
    bool facingLeft;
    float rotationSpeed;
    float rotation;

    virtual void move(unsigned long long delta) = 0;

public:

    ActiveActor(float x, float y, float w, float h) : Actor(x, y, w, h){}
    virtual void update(unsigned long long delta) = 0;

    //set velocity
    void setxVel(float x);
    void setyVel(float y);
    //some will not have implementation, dummy implement
    const virtual std::vector<std::shared_ptr<ActiveActor>> fireWeapon(float angle) {return {};}

    //get velocity values-> const
    const float& getxVel() const;
    const float& getyVel() const;



    //get gravity acceleration value
    const float& getbaseGravity() const;

    //collision detection methods
    const bool isColliding(const std::shared_ptr<InactiveActor> actor, unsigned long long delta);
    const bool isColliding(const std::shared_ptr<ActiveActor> actor, unsigned long long delta);
    void collisionReaction(unsigned long long delta);
    const bool sat(std::vector<std::vector<float>> shape1, std::vector<std::vector<float>> shape2) const;

    const int& getHitPoints(void) const {return hitPoints;}
    void setHitPoints(int hp) {hitPoints = hp;}
    virtual bool canFire() = 0;
    const bool& getIsInvincible(void) const {return isInvincible;}
    const float& getIFrames(void) const {return iFrames;}
    const int& getFlip(void) const {return gravityDirection;}
    const bool& getFaceLeft(void) const {return facingLeft;}
    const float& getRotation(void) const {return rotation;}

    void takeDamage(void);
};


#endif //CSCI437_ACTIVEACTOR_H
