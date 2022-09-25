//
// 
//

#include "PlatformActor.h"

PlatformActor::PlatformActor(float x,float y,float width, float height) : InactiveActor(x, y, width, height){
    doesDamage = false;
    isSolid = true;
    id = PLATFORM;
}

void PlatformActor::update(unsigned long long delta){
}