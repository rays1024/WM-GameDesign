//
// 
//

#include "SpikeActor.h"

SpikeActor::SpikeActor(float x,float y,float width, float height, int dir) : InactiveActor(x, y, width, height){
    doesDamage = true;
    isSolid = true;
    direction = dir;
    id = SPIKE;
}


void SpikeActor::update(unsigned long long delta){
}