
#include "ActiveActor.h"

void ActiveActor::setxVel(float x) {
    xVel = x;
}

void ActiveActor::setyVel(float y) {
    yVel = y;
}

const float& ActiveActor::getxVel() const {
    return xVel;
}

const float& ActiveActor::getyVel() const{
    return yVel;
}

const float& ActiveActor::getbaseGravity() const{
    return baseGravity;
}

const bool ActiveActor::isColliding(const std::shared_ptr<InactiveActor> actor, unsigned long long delta){
    std::vector<std::vector<float>> playerPoints;
    std::vector<std::vector<float>> actorPoints;

    //determines where the next player position is
    float nextX = posX + xVel * delta;
    float nextY;
    if (getActorType() == PLAYER || getActorType() == WALKING_ENEMY || getActorType() == LOBBING_ENEMY || getActorType() == ENEMY_LOBBING_PROJECTILE){
        nextY = posY + (yVel + baseGravity * gravityDirection * delta) * delta;
    }
    else if (getActorType() == PLAYER_PISTOL_PROJECTILE || getActorType() == PLAYER_SPREAD_PROJECTILE || getActorType() == ENEMY_PISTOL_PROJECTILE || getActorType() == TYRANTULA){
        nextY = posY + yVel * delta;
    }
    float midX;
    float midY;

    //simple checks to speed up collision detection
    //moving up and to the right
    if (xVel >= 0 && yVel <= 0){
        if ((posY + height < actor->getYPosition() || nextY > actor->getYPosition() + actor->getHeight()) || (nextX + width < actor->getXPosition() || posX > actor->getXPosition() + actor->getWidth())){
            return false;
        }
    }
    //moving down and to the right
    else if (xVel <= 0 && yVel <= 0){
        if ((nextY + height < actor->getYPosition() || posY > actor->getYPosition() + actor->getHeight()) || (nextX + width < actor->getXPosition() || posX > actor->getXPosition() + actor->getWidth())){
            return false;
        }
    }
    //moving up and to the left
    else if (xVel >= 0 && yVel >= 0){
        if ((posY + height < actor->getYPosition() || nextY > actor->getYPosition() + actor->getHeight()) || (posX + width < actor->getXPosition() || nextX > actor->getXPosition() + actor->getWidth())){
            return false;
        }
    }
    //moving down and to the left
    else if (xVel <= 0 && yVel >= 0){
        if ((nextY + height < actor->getYPosition() || posY > actor->getYPosition() + actor->getHeight()) || (posX + width < actor->getXPosition() || nextX > actor->getXPosition() + actor->getWidth())){
            return false;
        }
    }

    //set up the swept volume for the player depending on which
    //way they are currently traveling
    //moving up and to the right
    if (xVel >= 0 && yVel <= 0){
        playerPoints.push_back({posX,posY + height});
        playerPoints.push_back({posX,posY});
        playerPoints.push_back({nextX, nextY});
        playerPoints.push_back({nextX + width, nextY});
        playerPoints.push_back({nextX + width, nextY + height});
        playerPoints.push_back({posX + width,posY + height});
    }
    //moving down and to the right
    else if (xVel >= 0 && yVel >= 0){
        playerPoints.push_back({posX,posY});
        playerPoints.push_back({posX + width,posY});
        playerPoints.push_back({nextX + width, nextY});
        playerPoints.push_back({nextX + width, nextY + height});
        playerPoints.push_back({nextX, nextY + height});
        playerPoints.push_back({posX,posY + height});
    }
    //moving up and to the left
    else if (xVel <= 0 && yVel >= 0){
        playerPoints.push_back({posX + width,posY});
        playerPoints.push_back({posX + width,posY + height});
        playerPoints.push_back({nextX + width, nextY + height});
        playerPoints.push_back({nextX, nextY + height});
        playerPoints.push_back({nextX,nextY});
        playerPoints.push_back({posX,posY});
    }
    //moving down and to the left
    else if (xVel <= 0 && yVel <= 0){
        playerPoints.push_back({posX + width,posY + height});
        playerPoints.push_back({posX,posY + height});
        playerPoints.push_back({nextX, nextY + height});
        playerPoints.push_back({nextX,nextY});
        playerPoints.push_back({nextX + width, nextY});
        playerPoints.push_back({posX + width,posY});
    }

    //sets up the points for the actor
    actorPoints.push_back({actor->getXPosition(),actor->getYPosition()});
    actorPoints.push_back({actor->getXPosition() + actor->getWidth(),actor->getYPosition()});
    actorPoints.push_back({actor->getXPosition() + actor->getWidth(),actor->getYPosition() + actor->getHeight()});
    actorPoints.push_back({actor->getXPosition(),actor->getYPosition() + actor->getHeight()});

    //if the player would collide with the actor
    //find exactly where they collide with the 
    //actor at
    if (sat(playerPoints,actorPoints)){
        for (int i = 0; i < 10; i++){
            //find the midpoint between the current position and the next position
            midX = (playerPoints[0][0] + playerPoints[3][0]) / 2;
            midY = (playerPoints[0][1] + playerPoints[3][1]) / 2;

            std::vector<std::vector<float>> midPoints;

            //divide the swept volume in half and see if the first
            //half intersects
            midPoints.push_back(playerPoints[0]);
            midPoints.push_back(playerPoints[1]);
            if (xVel >= 0 && yVel <= 0){
                midPoints.push_back({midX - width / 2, midY - height / 2});
                midPoints.push_back({midX + width / 2, midY - height / 2});
                midPoints.push_back({midX + width / 2, midY + height / 2});
            }
            else if (xVel >= 0 && yVel >= 0){
                midPoints.push_back({midX + width / 2, midY - height / 2});
                midPoints.push_back({midX + width / 2, midY + height / 2});
                midPoints.push_back({midX - width / 2, midY + height / 2});
            }
            else if (xVel <= 0 && yVel >= 0){
                midPoints.push_back({midX + width / 2, midY + height / 2});
                midPoints.push_back({midX - width / 2, midY + height / 2});
                midPoints.push_back({midX - width / 2, midY - height / 2});
            }
            else if (xVel <= 0 && yVel <= 0){
                midPoints.push_back({midX - width / 2, midY + height / 2});
                midPoints.push_back({midX - width / 2, midY - height / 2});
                midPoints.push_back({midX + width / 2, midY - height / 2});
            }
            midPoints.push_back(playerPoints[5]);

            if (sat(midPoints,actorPoints)){
                playerPoints[2] = midPoints[2];
                playerPoints[3] = midPoints[3];
                playerPoints[4] = midPoints[4];
            }
            else{
                if (xVel >= 0 && yVel <= 0){
                    playerPoints[0] = {midX - width / 2, midY + height / 2};
                    playerPoints[1] = {midX - width / 2, midY - height / 2};
                    playerPoints[5] = {midX + width / 2, midY + height / 2};
                }
                else if (xVel >= 0 && yVel >= 0){
                    playerPoints[0] = {midX - width / 2, midY - height / 2};
                    playerPoints[1] = {midX + width / 2, midY - height / 2};
                    playerPoints[5] = {midX - width / 2, midY + height / 2};
                }
                else if (xVel <= 0 && yVel >= 0){
                    playerPoints[0] = {midX + width / 2, midY - height / 2};
                    playerPoints[1] = {midX + width / 2, midY + height / 2};
                    playerPoints[5] = {midX - width / 2, midY - height / 2};
                }
                else if (xVel <= 0 && yVel <= 0){
                    playerPoints[0] = {midX + width / 2, midY + height / 2};
                    playerPoints[1] = {midX - width / 2, midY + height / 2};
                    playerPoints[5] = {midX + width / 2, midY - height / 2};
                }
            }
        }
        //add actor to the list of potential actors the player could intersect with
        //this is needed if the player tunnels through multiple actors
        if (xVel >= 0 && yVel <= 0){
            potentialPoints.push_back({playerPoints[1][0],playerPoints[1][1]});
        }
        else if (xVel >= 0 && yVel >= 0){
            potentialPoints.push_back({playerPoints[0][0],playerPoints[0][1]});
        }
        else if (xVel <= 0 && yVel >= 0){
            potentialPoints.push_back({playerPoints[5][0],playerPoints[5][1]});
        }
        else if (xVel <= 0 && yVel <= 0){
            potentialPoints.push_back({playerPoints[0][0] - width,playerPoints[0][1] - height});
        }
        potentialCollisions.push_back(actor);
        return true;
    }
    else{
        return false;
    }
}

const bool ActiveActor::isColliding(const std::shared_ptr<ActiveActor> actor, unsigned long long delta){
    std::vector<std::vector<float>> actor1Points;
    std::vector<std::vector<float>> actor2Points;

    //determines where the next player position is
    float nextX = posX + xVel * delta;
    float nextXActor2 = actor->getXPosition() + actor->getxVel() * delta;
    float nextY;
    float nextYActor2 = actor->getYPosition() + actor->getyVel() * delta;
    float invertedX = nextXActor2 - 2 * (nextXActor2 - actor->getXPosition());
    float invertedY = nextYActor2 - 2 * (nextYActor2 - actor->getYPosition());
    if (getActorType() == PLAYER || getActorType() == WALKING_ENEMY || getActorType() == LOBBING_ENEMY || getActorType() == ENEMY_LOBBING_PROJECTILE){
        nextY = posY + (yVel + baseGravity * gravityDirection * delta) * delta;
    }
    else if (getActorType() == PLAYER_PISTOL_PROJECTILE || getActorType() == PLAYER_SPREAD_PROJECTILE || getActorType() == ENEMY_PISTOL_PROJECTILE || getActorType() == FLYING_ENEMY || getActorType() == TYRANTULA){
        nextY = posY + yVel * delta;
    }
    float adjustedX = invertedX + (nextX - actor->getXPosition());
    float adjustedY = invertedY + (nextY - actor->getYPosition());
    nextX = adjustedX;
    nextY = adjustedY;
    float midX;
    float midY;

    bool up = false;
    bool right = false;
    if (nextY - posY <= 0){
        up = true;
    }
    if (nextX - posX >= 0){
        right = true;
    }
    //simple checks to speed up collision detection
    //moving up and to the right
    if (up && right){
        if ((posY + height < actor->getYPosition() || nextY > actor->getYPosition() + actor->getHeight()) || (nextX + width < actor->getXPosition() || posX > actor->getXPosition() + actor->getWidth())){
            return false;
        }
    }
    //moving down and to the right
    else if (!up && right){
        if ((nextY + height < actor->getYPosition() || posY > actor->getYPosition() + actor->getHeight()) || (nextX + width < actor->getXPosition() || posX > actor->getXPosition() + actor->getWidth())){
            return false;
        }
    }
    //moving up and to the left
    else if (up && !right){
        if ((posY + height < actor->getYPosition() || nextY > actor->getYPosition() + actor->getHeight()) || (posX + width < actor->getXPosition() || nextX > actor->getXPosition() + actor->getWidth())){
            return false;
        }
    }
    //moving down and to the left
    else if (!up && !right){
        if ((nextY + height < actor->getYPosition() || posY > actor->getYPosition() + actor->getHeight()) || (posX + width < actor->getXPosition() || nextX > actor->getXPosition() + actor->getWidth())){
            return false;
        }
    }

    //set up the swept volume for the player depending on which
    //way they are currently traveling
    //moving up and to the right
    if (up && right){
        actor1Points.push_back({posX,posY + height});
        actor1Points.push_back({posX,posY});
        actor1Points.push_back({nextX, nextY});
        actor1Points.push_back({nextX + width, nextY});
        actor1Points.push_back({nextX + width, nextY + height});
        actor1Points.push_back({posX + width,posY + height});
    }
    //moving down and to the right
    else if (!up && right){
        actor1Points.push_back({posX,posY});
        actor1Points.push_back({posX + width,posY});
        actor1Points.push_back({nextX + width, nextY});
        actor1Points.push_back({nextX + width, nextY + height});
        actor1Points.push_back({nextX, nextY + height});
        actor1Points.push_back({posX,posY + height});
    }
    //moving up and to the left
    else if (up && !right){
        actor1Points.push_back({posX + width,posY});
        actor1Points.push_back({posX + width,posY + height});
        actor1Points.push_back({nextX + width, nextY + height});
        actor1Points.push_back({nextX, nextY + height});
        actor1Points.push_back({nextX,nextY});
        actor1Points.push_back({posX,posY});
    }
    //moving down and to the left
    else if (!up && !right){
        actor1Points.push_back({posX + width,posY + height});
        actor1Points.push_back({posX,posY + height});
        actor1Points.push_back({nextX, nextY + height});
        actor1Points.push_back({nextX,nextY});
        actor1Points.push_back({nextX + width, nextY});
        actor1Points.push_back({posX + width,posY});
    }

    //sets up the points for the actor
    actor2Points.push_back({actor->getXPosition(),actor->getYPosition()});
    actor2Points.push_back({actor->getXPosition() + actor->getWidth(),actor->getYPosition()});
    actor2Points.push_back({actor->getXPosition() + actor->getWidth(),actor->getYPosition() + actor->getHeight()});
    actor2Points.push_back({actor->getXPosition(),actor->getYPosition() + actor->getHeight()});

    //if the player would collide with the actor
    //find exactly where they collide with the 
    //actor at
    if (sat(actor1Points,actor2Points)){
        for (int i = 0; i < 10; i++){
            //find the midpoint between the current position and the next position
            midX = (actor1Points[0][0] + actor1Points[3][0]) / 2;
            midY = (actor1Points[0][1] + actor1Points[3][1]) / 2;

            std::vector<std::vector<float>> midPoints;

            //divide the swept volume in half and see if the first
            //half intersects
            midPoints.push_back(actor1Points[0]);
            midPoints.push_back(actor1Points[1]);
            if (xVel >= 0 && yVel <= 0){
                midPoints.push_back({midX - width / 2, midY - height / 2});
                midPoints.push_back({midX + width / 2, midY - height / 2});
                midPoints.push_back({midX + width / 2, midY + height / 2});
            }
            else if (xVel >= 0 && yVel >= 0){
                midPoints.push_back({midX + width / 2, midY - height / 2});
                midPoints.push_back({midX + width / 2, midY + height / 2});
                midPoints.push_back({midX - width / 2, midY + height / 2});
            }
            else if (xVel <= 0 && yVel >= 0){
                midPoints.push_back({midX + width / 2, midY + height / 2});
                midPoints.push_back({midX - width / 2, midY + height / 2});
                midPoints.push_back({midX - width / 2, midY - height / 2});
            }
            else if (xVel <= 0 && yVel <= 0){
                midPoints.push_back({midX - width / 2, midY + height / 2});
                midPoints.push_back({midX - width / 2, midY - height / 2});
                midPoints.push_back({midX + width / 2, midY - height / 2});
            }
            midPoints.push_back(actor1Points[5]);

            if (sat(midPoints,actor2Points)){
                actor1Points[2] = midPoints[2];
                actor1Points[3] = midPoints[3];
                actor1Points[4] = midPoints[4];
            }
            else{
                if (xVel >= 0 && yVel <= 0){
                    actor1Points[0] = {midX - width / 2, midY + height / 2};
                    actor1Points[1] = {midX - width / 2, midY - height / 2};
                    actor1Points[5] = {midX + width / 2, midY + height / 2};
                }
                else if (xVel >= 0 && yVel >= 0){
                    actor1Points[0] = {midX - width / 2, midY - height / 2};
                    actor1Points[1] = {midX + width / 2, midY - height / 2};
                    actor1Points[5] = {midX - width / 2, midY + height / 2};
                }
                else if (xVel <= 0 && yVel >= 0){
                    actor1Points[0] = {midX + width / 2, midY - height / 2};
                    actor1Points[1] = {midX + width / 2, midY + height / 2};
                    actor1Points[5] = {midX - width / 2, midY - height / 2};
                }
                else if (xVel <= 0 && yVel <= 0){
                    actor1Points[0] = {midX + width / 2, midY + height / 2};
                    actor1Points[1] = {midX - width / 2, midY + height / 2};
                    actor1Points[5] = {midX + width / 2, midY - height / 2};
                }
            }
        }
        //add actor to the list of potential actors the player could intersect with
        //this is needed if the player tunnels through multiple actors
        if (xVel >= 0 && yVel <= 0){
            potentialPoints.push_back({actor1Points[1][0],actor1Points[1][1]});
        }
        else if (xVel >= 0 && yVel >= 0){
            potentialPoints.push_back({actor1Points[0][0],actor1Points[0][1]});
        }
        else if (xVel <= 0 && yVel >= 0){
            potentialPoints.push_back({actor1Points[5][0],actor1Points[5][1]});
        }
        else if (xVel <= 0 && yVel <= 0){
            potentialPoints.push_back({actor1Points[0][0] - width,actor1Points[0][1] - height});
        }
        potentialCollisions.push_back(actor);
        return true;
    }
    else{
        return false;
    }
}

void ActiveActor::collisionReaction(unsigned long long delta){
    float minLDistance = std::numeric_limits<float>::infinity();
    float minRDistance = std::numeric_limits<float>::infinity();
    float minUDistance = std::numeric_limits<float>::infinity();
    float minDDistance = std::numeric_limits<float>::infinity();
    int indexL = -1;
    int indexR = -1;
    int indexU = -1;
    int indexD = -1;
    std::vector<float> closestPoint;

    //gets the actor closest to the player in the x and y directions
    for (int i = 0; i < potentialPoints.size(); i++){
        std::shared_ptr<Actor> actor = potentialCollisions[i];
        closestPoint = potentialPoints[i];

        //determine which side of the actor was collided with
        float disFromLeft = std::abs(closestPoint[0] + width - actor->getXPosition());
        float disFromRight = std::abs(actor->getXPosition() + actor->getWidth() - closestPoint[0]);
        float disFromTop = std::abs(closestPoint[1] + height - actor->getYPosition());
        float disFromBottom = std::abs(actor->getYPosition() + actor->getHeight() - closestPoint[1]);
        float shallow = std::min(std::min(disFromLeft, disFromRight),std::min(disFromTop, disFromBottom));
        if (shallow == disFromLeft){
            if (std::abs(potentialPoints[i][0] - posX) < minLDistance){
                minLDistance = std::abs(potentialPoints[i][0] - posX);
                indexL = i;
            }
        }
        else if (shallow == disFromRight){
            if (std::abs(potentialPoints[i][0] - posX) < minRDistance){
                minRDistance = std::abs(potentialPoints[i][0] - posX);
                indexR = i;
            }
        }
        else if (shallow == disFromTop){
            if (std::abs(potentialPoints[i][1] - posY) < minUDistance){
                minUDistance = std::abs(potentialPoints[i][1] - posY);
                indexU = i;
            }
        }
        else if (shallow == disFromBottom){
            if (std::abs(potentialPoints[i][1] - posY) < minDDistance){
                minDDistance = std::abs(potentialPoints[i][1] - posY);
                indexD = i;
            }
        }
    }

    std::shared_ptr<Actor> actor;

    if (indexL >= 0){
        actor = potentialCollisions[indexL];
        closestPoint = potentialPoints[indexL];
    }
    else if (indexR >= 0){
        actor = potentialCollisions[indexR];
        closestPoint = potentialPoints[indexR];
    }
    else if (indexU >= 0){
        actor = potentialCollisions[indexU];
        closestPoint = potentialPoints[indexU];
    }
    else if (indexD >= 0){
        actor = potentialCollisions[indexD];
        closestPoint = potentialPoints[indexD];
    }

    for (int i = 0; i < 4; i++){
        if ((indexL < 0 && i == 0) || (indexR < 0 && i == 1) || (indexU < 0 && i == 2) || (indexD < 0 && i == 3)){
            continue;
        }
        if (i == 1 && indexR >= 0 && indexR != indexL){
            actor = potentialCollisions[indexR];
            closestPoint = potentialPoints[indexR];
        }
        if (i == 2 && indexU >= 0 && indexU != indexR && indexU != indexL){
            actor = potentialCollisions[indexU];
            closestPoint = potentialPoints[indexU];
        }
        if (i == 3 && indexD >= 0 && indexD != indexU && indexD != indexR && indexD != indexL){
            actor = potentialCollisions[indexD];
            closestPoint = potentialPoints[indexD];
        }

        if ((getActorType() == PLAYER || getActorType() == WALKING_ENEMY || getActorType() == LOBBING_ENEMY || getActorType() == ENEMY_LOBBING_PROJECTILE) && (actor->getActorType() == PLATFORM || actor->getActorType() == SPIKE)){ //for both platform and spike. can change if needed
            //determine which side of the platform was collided with
            float disFromLeft = std::abs(closestPoint[0] + width - actor->getXPosition());
            float disFromRight = std::abs(actor->getXPosition() + actor->getWidth() - closestPoint[0]);
            float disFromTop = std::abs(closestPoint[1] + height - actor->getYPosition());
            float disFromBottom = std::abs(actor->getYPosition() + actor->getHeight() - closestPoint[1]);
            
            //get side that the player penetrated the least
            float shallow = std::min(std::min(disFromLeft, disFromRight),std::min(disFromTop, disFromBottom));
            if (shallow == disFromLeft){
                if (xVel > 0){
                    posX = actor->getXPosition() - width;
                    xVel = 0;
                }
                if (getActorType() == ENEMY_LOBBING_PROJECTILE){
                    hitPoints -= 1;
                }
            }
            else if (shallow == disFromRight){
                if (xVel < 0){
                    posX = actor->getXPosition() + actor->getWidth();
                    xVel = 0;
                }
                if (getActorType() == ENEMY_LOBBING_PROJECTILE){
                    hitPoints -= 1;
                }
            }
            else if (shallow == disFromTop){
                if (gravityDirection > 0){
                    onGround = true;
                }
                if (!(yVel < 0 && gravityDirection < 0) && gravityDirection > 0 && yVel >= 0){
                    posY = actor->getYPosition() - height;
                    if (getActorType() == ENEMY_LOBBING_PROJECTILE){
                        if (std::abs(yVel) > 0.5){
                            yVel *= -.8;
                        }
                        else{
                            yVel *= -1;
                        }
                    }
                    else{
                        yVel = 0;
                    }
                    yVel -= baseGravity * gravityDirection * delta;
                    if (getActorType() == PLAYER && actor->getActorType() == SPIKE){
                        takeDamage();
                    }
                }
                else if (!(yVel < 0 && gravityDirection < 0) && gravityDirection > 0){
                    posY = actor->getYPosition() - height;
                }
                else if (!(yVel < 0 && gravityDirection < 0)){
                    posY = actor->getYPosition() - height - 0.01;
                    yVel = 0;
                    yVel -= baseGravity * gravityDirection * delta;
                    if (getActorType() == PLAYER && actor->getActorType() == SPIKE){
                        takeDamage();
                    }
                }
            }
            else if (shallow == disFromBottom){
                if (gravityDirection < 0){
                    onGround = true;
                }
                if (!(yVel > 0 && gravityDirection > 0) && gravityDirection < 0 && yVel <= 0){
                    posY = actor->getYPosition() + actor->getHeight();
                    if (getActorType() == ENEMY_LOBBING_PROJECTILE){
                        if (std::abs(yVel) > 0.5){
                            yVel *= -.8;
                        }
                        else{
                            yVel *= -1;
                        }
                    }
                    else{
                        yVel = 0;
                    }
                    yVel -= baseGravity * gravityDirection * delta;
                    if (getActorType() == PLAYER && actor->getActorType() == SPIKE){
                        takeDamage();
                    }
                }
                else if (!(yVel > 0 && gravityDirection > 0) && gravityDirection < 0){
                    posY = actor->getYPosition() + actor->getHeight();
                }
                else if (!(yVel > 0 && gravityDirection > 0)){
                    posY = actor->getYPosition() + actor->getHeight() + 0.01;
                    yVel = 0;
                    yVel -= baseGravity * gravityDirection * delta;
                    if (getActorType() == PLAYER && actor->getActorType() == SPIKE){
                        takeDamage();
                    }
                }
            }
        }
        else if ((getActorType() == PLAYER_PISTOL_PROJECTILE || getActorType() == PLAYER_SPREAD_PROJECTILE) && actor->getActorType() != PLAYER){
            hitPoints -= 1;
        }
        else if ((getActorType() == ENEMY_PISTOL_PROJECTILE) && (actor->getActorType() == PLAYER || actor->getActorType() == PLATFORM || actor->getActorType() == SPIKE || actor->getActorType() == PLAYER_PISTOL_PROJECTILE || actor->getActorType() == PLAYER_SPREAD_PROJECTILE)){
            hitPoints -= 1;
        }
        else if (getActorType() == ENEMY_LOBBING_PROJECTILE && (actor->getActorType() == PLAYER || actor->getActorType() == PLAYER_PISTOL_PROJECTILE || actor->getActorType() == PLAYER_SPREAD_PROJECTILE )){
            hitPoints -= 1;
        }
        else if ((getActorType() == FLYING_ENEMY || getActorType() == WALKING_ENEMY || getActorType() == LOBBING_ENEMY || getActorType() == TYRANTULA) && (actor->getActorType() == PLAYER_PISTOL_PROJECTILE || actor->getActorType() == PLAYER_SPREAD_PROJECTILE)){
            hitPoints -= 1;
        }
        else if (getActorType() == PLAYER && (actor->getActorType() == FLYING_ENEMY || actor->getActorType() == WALKING_ENEMY || actor->getActorType() == LOBBING_ENEMY || actor->getActorType() == ENEMY_PISTOL_PROJECTILE || actor->getActorType() == ENEMY_LOBBING_PROJECTILE)){
            takeDamage();
        }
    }
    potentialCollisions.clear();
    potentialPoints.clear();
}

//https://gist.github.com/nyorain/dc5af42c6e83f7ac6d831a2cfd5fbece used as reference for separating
//axis theorem 
const bool ActiveActor::sat(std::vector<std::vector<float>> shape1, std::vector<std::vector<float>> shape2) const{
    for (int i = 0; i < shape1.size(); i++){
        std::vector<float> first_point = shape1[i];
        std::vector<float> next_point = shape1[(i + 1) % shape1.size()];
        std::vector<float> edge;
        edge.push_back(next_point[0] - first_point[0]);
        edge.push_back(next_point[1] - first_point[1]);

        //get normal for edge
        std::vector<float> normal = edge;
        normal[0] = -edge[1];
        normal[1] = edge[0];

        //project shapes onto normal
        float shape1Max = -std::numeric_limits<float>::infinity();
        float shape1Min = std::numeric_limits<float>::infinity();
        float shape2Max = -std::numeric_limits<float>::infinity();
        float shape2Min = std::numeric_limits<float>::infinity();

        for (int i = 0; i < shape1.size(); i++){
            float dot = shape1[i][0] * normal[0] + shape1[i][1] * normal[1];
            if (dot < shape1Min){
                shape1Min = dot;
            }
            if (dot > shape1Max){
                shape1Max = dot;
            }
        }
        for (int i = 0; i < shape2.size(); i++){
            float dot = shape2[i][0] * normal[0] + shape2[i][1] * normal[1];
            if (dot < shape2Min){
                shape2Min = dot;
            }
            if (dot > shape2Max){
                shape2Max = dot;
            }
        }

        if (shape1Max < shape2Min || shape1Min > shape2Max){
            return false;
        }
    }
    return true;
}

void ActiveActor::move(unsigned long long delta){

}

void ActiveActor::update(unsigned long long delta){

}

void ActiveActor::takeDamage(void){
    if (!isInvincible){
        hitPoints -= 1;
        iFrames = 2000;
        isInvincible = true;
    }
}