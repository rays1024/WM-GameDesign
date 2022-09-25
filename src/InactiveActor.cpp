
#include "InactiveActor.h"

void InactiveActor::setDoesDamage(bool x) {
    doesDamage = x;
}

void InactiveActor::setIsSolid(bool y) {
    isSolid = y;
}

const bool& InactiveActor::getDoesDamage() const{
    return doesDamage;
}

const bool& InactiveActor::getIsSolid() const{
    return isSolid;
}