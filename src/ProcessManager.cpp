
#include "ProcessManager.h"
#include <iostream>
#include <stdio.h>

void ProcessManager::init(){

    //should eventually take in a level descriptor file
    player = std::make_shared<PlayerProcess>(0);
    tinyxml2::XMLDocument xmlDoc;
    xmlDoc.LoadFile("../resource/level1.xml");
    extractXML(&xmlDoc);
    currentLevel = 1;
    playerShot = false;
    laserCode = 0;
}

bool ProcessManager::update(unsigned long long deltaMs){

    //check for respawn
    if (player->getPlayerActor()->getHitPoints()==0) levelTransition(false);
    if ((player->getPlayerActor()->getYPosition() < (-80) && player->getPlayerActor()->getFlip() == -1) || (player->getPlayerActor()->getYPosition() > SCREEN_HEIGHT && player->getPlayerActor()->getFlip() == 1)) levelTransition(false);
    
    //removes dead projectile processes
    projectileProcesses.erase(std::remove_if(projectileProcesses.begin(),projectileProcesses.end(),[] (const std::shared_ptr<ActiveProcess> & cur) {return cur->getState() == DESTROYED;}), projectileProcesses.end());
    //removes dead ai processes
    aiProcesses.erase(std::remove_if(aiProcesses.begin(),aiProcesses.end(),[] (const std::shared_ptr<ActiveProcess> & cur) {return cur->getState() == DESTROYED;}), aiProcesses.end());
    //removes dead health processes
    healthPickups.erase(std::remove_if(healthPickups.begin(),healthPickups.end(),[] (const std::shared_ptr<InactiveProcess> & cur) {return cur->getState() == DESTROYED;}), healthPickups.end());
    
    if (left && right){
        player->getPlayerActor()->leftRight(0);
    }
    else if (left){
        player->getPlayerActor()->leftRight(-1);
    }
    else if (right){
        player->getPlayerActor()->leftRight(1);
    }
    else{
        player->getPlayerActor()->leftRight(0);
    }

    if (jump){
        player->getPlayerActor()->jump();
    }

    if (flip){
        player->getPlayerActor()->flip();
        flip = false;
    }

    playerShot = false;
    if (shoot){
        if (std::abs((int) getAngle()) % 180 < 90 && std::abs((int) getAngle()) != 180){
            player->getPlayerActor()->leftRight(2);
        }
        else{
            player->getPlayerActor()->leftRight(-2);
        }
        for (auto projectile : player->getPlayerActor()->fireWeapon(getAngle())){
            playerShot = true;
            if (player->getPlayerActor()->getCurrentWeapon() == 1){
                projectileProcesses.push_back(std::make_shared<ActiveProcess>(PLAYER_PISTOL_PROJECTILE, projectile));
            }
            else if (player->getPlayerActor()->getCurrentWeapon() == 2){
                projectileProcesses.push_back(std::make_shared<ActiveProcess>(PLAYER_SPREAD_PROJECTILE, projectile));
            }
        }
    }

    //player colliding 
    for (auto platform : inactiveProcesses){
        if (player->getPlayerActor()->isColliding((platform->getActor()),deltaMs)){
            collide = true;
        }
    }
    for (auto ai : aiProcesses){
        if (player->getPlayerActor()->isColliding((ai->getActor()),deltaMs)){
            collide = true;
        }
    }
    for (auto projectile : projectileProcesses){
        if ((projectile->getActorId() == ENEMY_PISTOL_PROJECTILE || projectile->getActorId() == ENEMY_LOBBING_PROJECTILE) && player->getPlayerActor()->isColliding((projectile->getActor()),deltaMs)){
            collide = true;
        }
    }

    if (collide){
        player->getPlayerActor()->collisionReaction(deltaMs);
    }
    collide = false;

    //level end collision
    if (player->getPlayerActor()->isColliding((endLevel->getActor()), deltaMs)){
        levelTransition(true);
    }

    //health collision
    for (auto healthPickup : healthPickups){
    if (player->getPlayerActor()->isColliding((healthPickup->getActor()), deltaMs) && player->getState() == RUNNING){
        player->getPlayerActor()->heal();
        healthPickup->setState(DESTROYED);}
    }

    for (auto projectile : projectileProcesses){
        for (auto platform : inactiveProcesses){
            if (projectile->getActor()->isColliding((platform->getActor()),deltaMs)){
                collide = true;
            }
        }
        for (auto ai : aiProcesses){
            if ((projectile->getActorId() == PLAYER_PISTOL_PROJECTILE || projectile->getActorId() == PLAYER_SPREAD_PROJECTILE) && ai->getActorId() != LEG && projectile->getActor()->isColliding((ai->getActor()),deltaMs)){
                collide = true;
            }
        }
        for (auto projectile2 : projectileProcesses){
            if (((projectile->getActorId() == PLAYER_PISTOL_PROJECTILE || projectile->getActorId() == PLAYER_SPREAD_PROJECTILE) && (projectile2->getActorId() == ENEMY_PISTOL_PROJECTILE || projectile2->getActorId() == ENEMY_LOBBING_PROJECTILE)) && projectile->getActor()->isColliding((projectile2->getActor()),deltaMs)){
                collide = true;
            }
            if (((projectile->getActorId() == ENEMY_PISTOL_PROJECTILE || projectile->getActorId() == ENEMY_LOBBING_PROJECTILE) && (projectile2->getActorId() == PLAYER_PISTOL_PROJECTILE || projectile2->getActorId() == PLAYER_SPREAD_PROJECTILE)) && projectile->getActor()->isColliding((projectile2->getActor()),deltaMs)){
                collide = true;
            }
        }
        if ((projectile->getActorId() == ENEMY_PISTOL_PROJECTILE || projectile->getActorId() == ENEMY_LOBBING_PROJECTILE) && projectile->getActor()->isColliding((player->getPlayerActor()),deltaMs)){
            collide = true;
        }
        if (collide){
            projectile->getActor()->collisionReaction(deltaMs);
        }
        collide = false;
    }

    for (std::shared_ptr<ActiveProcess> curAI : aiProcesses){
        if (curAI->getActorId() != LEG){
            for (auto platform : inactiveProcesses){
                if (curAI->getActorId() != FLYING_ENEMY && curAI->getActor()->isColliding((platform->getActor()),deltaMs)){
                    collide = true;
                }
            }
            for (auto projectile : projectileProcesses){
                if ((projectile->getActorId() == PLAYER_PISTOL_PROJECTILE || projectile->getActorId() == PLAYER_SPREAD_PROJECTILE) && curAI->getActor()->isColliding((projectile->getActor()),deltaMs)){
                    collide = true;
                }
            }
            if (collide){
                curAI->getActor()->collisionReaction(deltaMs);
            }
            collide = false;
            if (curAI->getActorId() == TYRANTULA){
                if (curAI->getActor()->getXPosition() + curAI->getActor()->getWidth() > player->getPlayerActor()->getXPosition()){
                    player->getPlayerActor()->takeDamage();
                    player->getPlayerActor()->setXPosition(player->getPlayerActor()->getXPosition() + 300);
                }
                if (player->getPlayerActor()->getXPosition() + player->getPlayerActor()->getWidth() > curAI->getActor()->getXPosition() + 914){
                    player->getPlayerActor()->setXPosition(curAI->getActor()->getXPosition() + 914 - player->getPlayerActor()->getWidth());
                }
            }
        }
    }

    //update everything
    player->getPlayerActor()->update(deltaMs);
    for (auto projectile : projectileProcesses){
        projectile->update(deltaMs);
    }
    for (auto ai : aiProcesses){
        ai->update(deltaMs);
        if (ai->getActorId() == TYRANTULA && ai->getActor()->getHitPoints() <= 0){
            for (auto ai2 : aiProcesses){
                if (ai2->getActorId() == LEG){
                    ai2->getActor()->setHitPoints(0);
                }
            }
        }
    }

    return true;

}

void ProcessManager::setInput(int button, int action){
    if (button == 0){
        if (action == 1){
            left = true;
        }
        else{
            left = false;
        }
    }
    else if (button == 1){
        if (action == 1){
            right = true;
        }
        else{
            right = false;
        }
    }
    else if (button == 2){
        if (action == 1){
            jump = true;
        }
        else{
            jump = false;
        }
    }
    else if (button == 3){
        flip = true;
    }
    else if (button == 4){
        if (action == 1){
            shoot = true;
        }
        else{
            shoot = false;
        }
    }
    else if (button == 5){
        player->getPlayerActor()->setCurWeapon(action);
    }
    else if (button == 6){
        if (action == 1){
            if (laserCode == 0){
                laserCode++;
            }
            else{
                laserCode = 1;
            }
        }
        else if (action == 2 && laserCode == 1){
            laserCode++;
        }
        else if (action == 3 && laserCode == 2){
            laserCode++;
        }
        else if (action == 4 && laserCode == 3){
            laserCode++;
        }
        else if (action == 5 && laserCode == 4){
            player->getPlayerActor()->setLaser(true);
        }
        else{
            laserCode = 0;
        }
    }

}


void ProcessManager::extractXML(tinyxml2::XMLDocument * xmlDoc){

    tinyxml2::XMLNode * pRoot = xmlDoc->FirstChildElement("root");
    if (pRoot == nullptr) std::cout << "No root element in XML.\n";

    tinyxml2::XMLNode * pPlatform = pRoot->FirstChildElement("platform");
    if (pPlatform == nullptr) std::cout << "No platform data in xml.\n";

    tinyxml2::XMLNode * pSpike = pRoot->FirstChildElement("spike");
    if (pSpike == nullptr) std::cout << "No spike data in xml.\n";

    tinyxml2::XMLNode * pWalking = pRoot->FirstChildElement("walkingEnemy");
    if (pWalking == nullptr) std::cout << "No walkingEnemy data in xml.\n";

    tinyxml2::XMLNode * pFlying = pRoot->FirstChildElement("flyingEnemy");
    if (pFlying == nullptr) std::cout << "No flyingEnemy data in xml.\n";

    tinyxml2::XMLNode * pLobbing = pRoot->FirstChildElement("lobbingEnemy");
    if (pLobbing == nullptr) std::cout << "No lobbingEnemy data in xml.\n";

    tinyxml2::XMLNode * pPickup = pRoot->FirstChildElement("levelPickup");
    if (pPickup == nullptr) std::cout << "No levelPickup data in xml.\n";

    tinyxml2::XMLNode * pHealth = pRoot->FirstChildElement("healthPickup");
    if (pPickup == nullptr) std::cout << "No healthPickup data in xml.\n";

    tinyxml2::XMLNode * pLeg = pRoot->FirstChildElement("leg");
    if (pLeg == nullptr) std::cout << "No leg data in xml.\n";

    tinyxml2::XMLNode * pTyrantula = pRoot->FirstChildElement("tyrantula");
    if (pTyrantula == nullptr) std::cout << "No tyrantula data in xml.\n";

    int xpos;
    int ypos;
    int width;
    int height;
    int direction;
    int xBorder1;
    int xBorder2;
    int hpFlip;

    tinyxml2::XMLNode * current;

    for (current = pPlatform->FirstChildElement(); current != NULL; current = current->NextSibling())
    {
        current->FirstChildElement("xpos")->ToElement()->QueryIntText(&xpos);
        current->FirstChildElement("ypos")->ToElement()->QueryIntText(&ypos);
        current->FirstChildElement("width")->ToElement()->QueryIntText(&width);
        current->FirstChildElement("height")->ToElement()->QueryIntText(&height);

        inactiveProcesses.push_back(std::make_shared<InactiveProcess>(0, std::shared_ptr<InactiveActor>( new PlatformActor(xpos,ypos,width,height))));
    }

    for (current = pSpike->FirstChildElement(); current != NULL; current = current->NextSibling())
    {
        current->FirstChildElement("xpos")->ToElement()->QueryIntText(&xpos);
        current->FirstChildElement("ypos")->ToElement()->QueryIntText(&ypos);
        current->FirstChildElement("width")->ToElement()->QueryIntText(&width);
        current->FirstChildElement("height")->ToElement()->QueryIntText(&height);
        current->FirstChildElement("direction")->ToElement()->QueryIntText(&direction);

        inactiveProcesses.push_back(std::make_shared<InactiveProcess>(0, std::shared_ptr<InactiveActor>( new SpikeActor(xpos,ypos,width,height,direction))));
    }
    for (current = pWalking->FirstChildElement(); current != NULL; current = current->NextSibling())
    {
        current->FirstChildElement("xpos")->ToElement()->QueryIntText(&xpos);
        current->FirstChildElement("ypos")->ToElement()->QueryIntText(&ypos);
        current->FirstChildElement("width")->ToElement()->QueryIntText(&width);
        current->FirstChildElement("height")->ToElement()->QueryIntText(&height);
        current->FirstChildElement("xborder1")->ToElement()->QueryIntText(&xBorder1);
        current->FirstChildElement("xborder2")->ToElement()->QueryIntText(&xBorder2);

        aiProcesses.push_back(std::make_shared<ActiveProcess>(WALKING_ENEMY, std::shared_ptr<ActiveActor>( new WalkingEnemyActor(xpos,ypos,width,height, xBorder1, xBorder2))));
    }

    for (current = pFlying->FirstChildElement(); current != NULL; current = current->NextSibling())
    {
        current->FirstChildElement("xpos")->ToElement()->QueryIntText(&xpos);
        current->FirstChildElement("ypos")->ToElement()->QueryIntText(&ypos);
        current->FirstChildElement("width")->ToElement()->QueryIntText(&width);
        current->FirstChildElement("height")->ToElement()->QueryIntText(&height);

        aiProcesses.push_back(std::make_shared<ActiveProcess>(FLYING_ENEMY, std::shared_ptr<ActiveActor>( new FlyingEnemyActor(xpos,ypos,width,height))));
    }
    for (current = pLobbing->FirstChildElement(); current != NULL; current = current->NextSibling())
    {
        current->FirstChildElement("xpos")->ToElement()->QueryIntText(&xpos);
        current->FirstChildElement("ypos")->ToElement()->QueryIntText(&ypos);
        current->FirstChildElement("width")->ToElement()->QueryIntText(&width);
        current->FirstChildElement("height")->ToElement()->QueryIntText(&height);

        aiProcesses.push_back(std::make_shared<ActiveProcess>(LOBBING_ENEMY, std::shared_ptr<ActiveActor>( new LobbingEnemyActor(xpos,ypos,width,height))));
    }

    for (current = pLeg->FirstChildElement(); current != NULL; current = current->NextSibling())
    {
        float angle;
        int startDirection;
        current->FirstChildElement("xpos")->ToElement()->QueryIntText(&xpos);
        current->FirstChildElement("ypos")->ToElement()->QueryIntText(&ypos);
        current->FirstChildElement("width")->ToElement()->QueryIntText(&width);
        current->FirstChildElement("height")->ToElement()->QueryIntText(&height);
        current->FirstChildElement("angle")->ToElement()->QueryFloatText(&angle);
        current->FirstChildElement("start")->ToElement()->QueryIntText(&startDirection);

        if (std::abs(angle) < 90){
            aiProcesses.push_back(std::make_shared<ActiveProcess>(LEG, std::shared_ptr<ActiveActor>( new LegActor(xpos,ypos,width,234,45,startDirection,NULL))));
        }
        else{
            aiProcesses.push_back(std::make_shared<ActiveProcess>(LEG, std::shared_ptr<ActiveActor>( new LegActor(xpos,ypos,width,234,135,startDirection,NULL))));
        }

        aiProcesses.push_back(std::make_shared<ActiveProcess>(LEG, std::shared_ptr<ActiveActor>( new LegActor(xpos,ypos,width,height,angle,startDirection,aiProcesses[aiProcesses.size()-1]->getActor()))));
    }

    for (current = pTyrantula->FirstChildElement(); current != NULL; current = current->NextSibling())
    {
        current->FirstChildElement("xpos")->ToElement()->QueryIntText(&xpos);
        current->FirstChildElement("ypos")->ToElement()->QueryIntText(&ypos);
        current->FirstChildElement("width")->ToElement()->QueryIntText(&width);
        current->FirstChildElement("height")->ToElement()->QueryIntText(&height);

        aiProcesses.push_back(std::make_shared<ActiveProcess>(TYRANTULA, std::shared_ptr<ActiveActor>( new TyrantulaActor(xpos,ypos,width,height))));
    }

    for (current = pPickup->FirstChildElement(); current != NULL; current = current->NextSibling())
    {
        current->FirstChildElement("xpos")->ToElement()->QueryIntText(&xpos);
        current->FirstChildElement("ypos")->ToElement()->QueryIntText(&ypos);
        current->FirstChildElement("width")->ToElement()->QueryIntText(&width);
        current->FirstChildElement("height")->ToElement()->QueryIntText(&height);
        //make new pickup and set it to level pickup
        std::shared_ptr<PickupActor> endLevelActor = std::shared_ptr<PickupActor>(new PickupActor(xpos, ypos, width, height, true));
        endLevelActor->setPickupType(LEVEL_PICKUP);
        endLevel = std::make_shared<InactiveProcess>(LEVEL_PICKUP, endLevelActor);
    }

    for (current = pHealth->FirstChildElement(); current != NULL; current = current->NextSibling())
    {
        current->FirstChildElement("xpos")->ToElement()->QueryIntText(&xpos);
        current->FirstChildElement("ypos")->ToElement()->QueryIntText(&ypos);
        current->FirstChildElement("width")->ToElement()->QueryIntText(&width);
        current->FirstChildElement("height")->ToElement()->QueryIntText(&height);
        current->FirstChildElement("flipped")->ToElement()->QueryIntText(&hpFlip);
        bool flipped = hpFlip == 1 ? false : true;
        //make new pickup and set it to level pickup
        std::shared_ptr<PickupActor> healthActor = std::shared_ptr<PickupActor>(new PickupActor(xpos, ypos, width, height, flipped));
        healthActor->setPickupType(HEALTH_PICKUP);
        healthPickups.push_back(std::make_shared<InactiveProcess>(HEALTH_PICKUP, healthActor));
    }
}

void ProcessManager::levelTransition(bool newLevel){

    if (newLevel == true) currentLevel++;
    inactiveProcesses.clear();
    aiProcesses.clear();
    projectileProcesses.clear();
    healthPickups.clear();
    tinyxml2::XMLDocument xmlDoc;
    std::string filePath = "../resource/level" + std::to_string(currentLevel) + ".xml";
    xmlDoc.LoadFile(filePath.data());
    extractXML(&xmlDoc);
    //grab previous player HP and weapon for smooth transition to next level 
    int tempHP, tempWeapon, tempLaser;
    tempHP = player->getPlayerActor()->getHitPoints();
    tempWeapon = player->getPlayerActor()->getCurrentWeapon();
    tempLaser = player->getPlayerActor()->getLaser();
    player = std::make_shared<PlayerProcess>(0);
    player->getPlayerActor()->setLaser(tempLaser);
    //if transitioning to new level, retain current HP and weapon
    if (newLevel == true){
    player->getPlayerActor()->setCurWeapon(tempWeapon);
    player->getPlayerActor()->setHitPoints(tempHP);
    }
    //level 3 has different starting pos
    if (currentLevel == 3){
        player->getPlayerActor()->setXPosition(600);
        player->getPlayerActor()->setYPosition(384);
    }

    //player->setPosition(starting pos)
}

void ProcessManager::enemyFire(std::shared_ptr<ActiveProcess> enemy, int angle){
    std::shared_ptr<ActiveActor> actor = enemy->getActor();
    if (actor->getActorType() == WALKING_ENEMY){
     for (auto projectile : actor->fireWeapon(angle)){
                projectileProcesses.push_back(std::make_shared<ActiveProcess>(ENEMY_PISTOL_PROJECTILE, projectile));
            }
        }
    if (actor->getActorType() == LOBBING_ENEMY){
     for (auto projectile : actor->fireWeapon(angle)){
                projectileProcesses.push_back(std::make_shared<ActiveProcess>(ENEMY_LOBBING_PROJECTILE, projectile));
            }
        }
    //spread, wall, and normal shots make pistol projectiles
    if (actor->getActorType() == TYRANTULA && (angle == 361 || angle == 364 || angle < 360)){
        for (auto projectile : actor->fireWeapon(angle)){
            projectileProcesses.push_back(std::make_shared<ActiveProcess>(ENEMY_PISTOL_PROJECTILE, projectile));
        }
    }
    //boundcing shots make lobbing projectiles
     if (actor->getActorType() == TYRANTULA && (angle == 362 || angle == 363)){
        for (auto projectile : actor->fireWeapon(angle)){
            projectileProcesses.push_back(std::make_shared<ActiveProcess>(ENEMY_LOBBING_PROJECTILE, projectile));
        }
    }
}

void ProcessManager::destroy(){
    //all processes have a destructor in parent class Process()
    //these should delete the associated actors properly
    inactiveProcesses.clear();
    aiProcesses.clear();

    //also make sure player is deleted
}

