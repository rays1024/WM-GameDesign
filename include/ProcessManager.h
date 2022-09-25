//
// Manages what elements of the game are currently running, present, paused, or killed.
// Also acts as the interface for views to retrieve game information for drawing and decision-making.
//

#ifndef CSCI437_PROCESSMANAGER_H
#define CSCI437_PROCESSMANAGER_H

#include "Process.h"
#include "PlayerActor.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "ActiveProcess.h"
#include "InactiveProcess.h"
#include "PlayerProcess.h"
#include "tinyxml2.h"
#include "WalkingEnemyActor.h"
#include "ProjectileActor.h"
#include "FlyingEnemyActor.h"
#include "LobbingEnemyActor.h"
#include "PickupActor.h"
#include "LegActor.h"
#include "TyrantulaActor.h"

class ProcessManager {

private:

    std::vector<std::shared_ptr<ActiveProcess>> aiProcesses;
    std::vector<std::shared_ptr<ActiveProcess>> projectileProcesses;
    std::vector<std::shared_ptr<InactiveProcess>> inactiveProcesses;
    std::vector<std::shared_ptr<InactiveProcess>> healthPickups;
    std::shared_ptr<PlayerProcess> player;
    std::shared_ptr<InactiveProcess> endLevel;
    bool collide = false;
    bool left = false;
    bool right = false;
    bool jump = false;
    bool flip = false;
    bool shoot = false;
    bool playerShot;
    int currentLevel;
    int laserCode;


public:

    //initialize the gamestate,
    //should eventually take in an XML file to initialize a full level
    void init();
    
    //caller needs to explicitly initialize, have them explicitly destroy
    void destroy();


    //should return whether the game is still running
    //updates all processes (entities) in the game
    bool update(unsigned long long deltaMs);

    std::shared_ptr<PlayerActor> getPlayer() const {return player->getPlayerActor();}
    void setInput(int button, int action);
    void levelTransition(bool newLevel);
    //should only contain AI processes
    const std::vector<std::shared_ptr<ActiveProcess>>& getAIProcesses() const {return aiProcesses;}
    const std::vector<std::shared_ptr<ActiveProcess>>& getProjectileProcesses() const {return projectileProcesses;}
    const std::vector<std::shared_ptr<InactiveProcess>>& getInactiveProcesses() const {return inactiveProcesses;}
    const std::vector<std::shared_ptr<InactiveProcess>>& getHealthProcesses() const {return healthPickups;}
    const std::shared_ptr<InactiveProcess>& getLevelEndPickup() const {return endLevel;}


    void enemyFire(std::shared_ptr<ActiveProcess> enemy, int angle);
    void extractXML(tinyxml2::XMLDocument * xmlDoc);

    float angle;
    void setAngle(float a) {angle = a;}
    const float& getAngle() const {return angle;}

    const int& getCurrentLevel() const {return currentLevel;}
    const bool& playerJustShot(void) const {return playerShot;}

};


#endif //CSCI437_PROCESSMANAGER_H
