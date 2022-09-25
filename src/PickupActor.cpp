//
// Created by Matthew Reid on 3/19/2022.
//

#include "PickupActor.h"

PickupActor::PickupActor(float x, float y, float w, float h, bool flip) : InactiveActor(x, y, w, h) {
    this->posX = x;
    this->posY = y;
    this->width = width;
    this->height = height;
    this->direction = flip;
    //initialize doesDamage and isSolid to False initially
    doesDamage = false;
    isSolid = true;
    id = HEALTH_PICKUP;
}

void PickupActor::update(unsigned long long delta){
    //
}

 void PickupActor::setPickupType(int id){
     this->id = id;
 }