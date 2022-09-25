#include "AIView.h"

AIView::AIView(const std::shared_ptr<ProcessManager> manager){
    this->manager = manager;
    flyingTurnAround = FLYING_TURN_INTERVAL;
    lobbingEnemyJump = LOBBING_JUMP_INTERVAL;
    bossAttackTimer = 0;
    currentBossAttack = WALL;
    flyingTurn = false;
    jumpingTime = false;
    bigAttackHappened = false;
}

void AIView::makeDecision(unsigned long long delta){
    //flying enemies turn every 3 seconds on global timer
    if (flyingTurnAround <= 0){
        flyingTurn = true;
        flyingTurnAround = FLYING_TURN_INTERVAL;
    }
    else{
        flyingTurn = false;
        flyingTurnAround -= delta;
    }

    flyingTurnAround -= delta;

    if (lobbingEnemyJump <= 0){
        jumpingTime = true;
        lobbingEnemyJump = LOBBING_JUMP_INTERVAL;
    }
    else{
        jumpingTime = false;
        lobbingEnemyJump -= delta;
    }

    lobbingEnemyFire-= delta;
    
    for (std::shared_ptr<ActiveProcess> process : manager->getAIProcesses()){

    //using state of game from stored ProcessManager pointer,
    //get the necessary information and make a decision, based on actor ID
        float playerX = manager->getPlayer()->getXPosition();
        float playerY = manager->getPlayer()->getYPosition();

        float enemyX = process->getActor()->getXPosition();
        float enemyY = process->getActor()->getYPosition();

        //double delta = SDL_GetTicks64() - timeTracker;

        if (process->getActorId() == FLYING_ENEMY){
            if (flyingTurn){
                process->getActor()->setxVel(-(process->getActor()->getxVel()));
                }
        }
        else if (process->getActorId() == WALKING_ENEMY){
            if (process->getActor()->canFire()){
                //if ready to fire, calculate a shot angle
                //bool for checking if player at impossible to hit angle
                bool willFire = true;
                //calculate angle directly to player
                float angleX = playerX - enemyX;
                float angleY = enemyY - playerY;
                float angle = (atan2(angleY, angleX) * 180) / (double) 3.141592;
                //try to correct angles if they are going to shoot into the floor,
                //if player is directly under, dont shoot
                if (angle > (float) -180 && angle < (float) -135) angle = (float) -180;
                else if (angle > (float) -45 && angle < (float) 0) angle = (float) 0;
                else if (angle > (float) -135 && angle < (float) -45) willFire = false;
                //fire
                if (willFire) manager->enemyFire(process, angle);
            }
        }
        else if (process->getActorId() == LOBBING_ENEMY){
            if (process->getActor()->canFire()){
                //randomly choose angle within 45 degrees of appropriate direction
                float randomAngleChange = (float) (rand() % 45);
                //set negative if in bottom half of possibilities
                if (randomAngleChange < 23) randomAngleChange *= -1;
                else randomAngleChange = (45 - randomAngleChange);
                if (playerX - enemyX > 0){
                    manager->enemyFire(process, (float) 45 + randomAngleChange);
                }
                else if (enemyX - playerX > 0){
                    manager->enemyFire(process, (float) 135 + randomAngleChange);
                }
            }
            //if it is time for jumping, jump
            if (jumpingTime){
                process->getActor()->setyVel(-1.2);
                lobbingEnemyJump = LOBBING_JUMP_INTERVAL;
            }
        }
        else if (process->getActorId() == TYRANTULA){
            if (bossAttackTimer <= 0){
                //random between all except None and Crazy attacks
                currentBossAttack = rand() % (BOSS_ATTACK_NUM-2) + 1;
                //check if the crazy attack should happen instead
                if (process->getActor()->getHitPoints() == 100) bigAttackHappened = false;
                //guaranteed to do crazy attack once at half hp
                if (process->getActor()->getHitPoints() < 45 && !bigAttackHappened){
                    currentBossAttack = CRAZY;
                    bigAttackHappened = true;
                }
                //then, have a 30% chance
                else if (process->getActor()->getHitPoints() < 30 && (rand() % 3 == 1)) currentBossAttack = CRAZY;
                //set attack duration
                switch(currentBossAttack){
                    case WALL:
                        bossAttackTimer = 3000;
                        break;
                    case LOBBING_DOWN:
                        bossAttackTimer = 10000;
                        break;
                    case LOBBING_UP:
                        bossAttackTimer = 10000;
                        break;
                    case LASER:
                        bossAttackTimer = 5000;
                        break;
                    case SPREAD:
                        bossAttackTimer = 3000;
                        break;
                    case CRAZY:
                        bossAttackTimer = 12000;
                        break;
                    }
                }

            switch(currentBossAttack){
                case NONE:
                    //each attack handles timer differently:
                    //if no attack, simply count down
                    bossAttackTimer -= delta;
                    break;
                case WALL:
                    wallAttack(delta, process);
                    break;
                case LOBBING_DOWN:
                    bouncingAttack(delta, process, true);
                    break;
                case LOBBING_UP:
                    bouncingAttack(delta, process, false);
                    break;
                case LASER:
                    laserAttack(delta, process);
                    break;
                case SPREAD:
                    spreadAttack(delta, process);
                    break;
                case CRAZY:
                    crazyAttack(delta, process);
                    break;
            }
        }
    }
}

void AIView::wallAttack(unsigned long long delta, std::shared_ptr<ActiveProcess> process){
    static float wallAttackTimer = 0;
    wallAttackTimer += delta;
    //shoot wall of bullets every ... seconds
    if (wallAttackTimer >= 800){
        //361 = wall attack
        manager->enemyFire(process, 361);
        wallAttackTimer -= 800;
    }
    bossAttackTimer -= delta;
    if (bossAttackTimer <= 0){
        //no attacks for 2 seconds after wall attack
        currentBossAttack = NONE;
        //1 second cooloff at high health, 0.5 at low
        if (process->getActor()->getHitPoints() > 45) bossAttackTimer = 1000;
        else bossAttackTimer = 500;
        wallAttackTimer = 0;
    }
}

void AIView::bouncingAttack(unsigned long long delta, std::shared_ptr<ActiveProcess> process, bool dirFlag){
    static float bounceAttackTimer = 0;
    static float singleShotTimer = 0;
    static float bounceDownTimer = 0;
    bounceAttackTimer += delta;
    bounceDownTimer += delta;
    singleShotTimer += delta;
    //shoot a bouncing bullet every .. seconds
    if ((bounceDownTimer <= 5000 && dirFlag == true) || (bounceDownTimer >= 5000 && dirFlag == false) ){
        if (bounceAttackTimer >= 100){
            //362 = bouncing attack
            manager->enemyFire(process, 362);
            bounceAttackTimer -= 100;
        }
    }
    else if (bounceAttackTimer >=100){
        //362 = bouncing attack
        manager->enemyFire(process, 363);
        bounceAttackTimer -= 100;
    }
    if (singleShotTimer >= 800){
        // <360 = normal attack
        //calculate angle towards player
        float playerX = manager->getPlayer()->getXPosition() + manager->getPlayer()->getWidth() ;
        float playerY = manager->getPlayer()->getYPosition();

        float enemyX = process->getActor()->getXPosition() + (process->getActor()->getWidth() / 2);
        float enemyY = process->getActor()->getYPosition() + (process->getActor()->getHeight() / 2);

        float angleX = playerX - enemyX;
        float angleY = enemyY - playerY;
        float angle = (atan2(angleY, angleX) * 180) / (double) 3.141592;
        manager->enemyFire(process, angle);
        singleShotTimer -= 800;
    }

    bossAttackTimer -= delta;
    if (bossAttackTimer <= 0){
        //no attacks for 2 seconds after wall attack
        currentBossAttack = NONE;
        //1.5 second cooloff at high health, 0.3 at low
        if (process->getActor()->getHitPoints() > 45) bossAttackTimer = 1500;
        else bossAttackTimer = 300;
        bounceDownTimer = 0;
        bounceAttackTimer = 0;
    }
}

void AIView::laserAttack(unsigned long long delta, std::shared_ptr<ActiveProcess> process){
    static float laserAttackTimer = 0;
    laserAttackTimer += delta;
    //shoot wall of bullets every ... seconds
    if (laserAttackTimer >= 40){
        //361 = wall attack
        float playerX = manager->getPlayer()->getXPosition() + manager->getPlayer()->getWidth() ;
        float playerY = manager->getPlayer()->getYPosition();

        float enemyX = process->getActor()->getXPosition() + (process->getActor()->getWidth() / 2);
        float enemyY = process->getActor()->getYPosition() + (process->getActor()->getHeight() / 2);

        float angleX = playerX - enemyX;
        float angleY = enemyY - playerY;
        float angle = (atan2(angleY, angleX) * 180) / (double) 3.141592;
        manager->enemyFire(process, angle);
        laserAttackTimer -= 40;
    }
    bossAttackTimer -= delta;
    if (bossAttackTimer <= 0){
        //no attacks for 2 seconds after wall attack
        currentBossAttack = NONE;
        //1 second cooloff at high health, 0.5 at low
        if (process->getActor()->getHitPoints() > 45) bossAttackTimer = 1500;
        else bossAttackTimer = 500;
        laserAttackTimer = 0;
    }
}

void AIView::spreadAttack(unsigned long long delta, std::shared_ptr<ActiveProcess> process){
    static float spreadAttackTimer = 0;
    spreadAttackTimer += delta;
    //shoot wall of bullets every ... seconds
    if (spreadAttackTimer >= 500){
        //361 = wall attack
        manager->enemyFire(process, 364);
        spreadAttackTimer -= 500;
    }
    bossAttackTimer -= delta;
    if (bossAttackTimer <= 0){
        //no attacks for 2 seconds after wall attack
        currentBossAttack = NONE;
        //0.8 second cooloff at high health, 0.4 at low
        if (process->getActor()->getHitPoints() > 40) bossAttackTimer = 800;
        else bossAttackTimer = 400;
        spreadAttackTimer = 0;
    }
}

void AIView::crazyAttack(unsigned long long delta, std::shared_ptr<ActiveProcess> process){
    static float spreadAttackTimer = 0;
    static float wallAttackTimer = 0;
    static float switchTimer = 0;
    spreadAttackTimer += delta;
    //shooting a spread of bullets every 0.8 seconds
    if (spreadAttackTimer >= 800){
        //361 = wall attack
        manager->enemyFire(process, 364);
        spreadAttackTimer -= 800;
    }
    static float laserAttackTimer = 0;
    //shoot two rounds of a short laser attack
    if ((switchTimer >= 8000 && switchTimer <= 9000) || (switchTimer >= 10000 && switchTimer <= 11000)){
        laserAttackTimer += delta;
        if (laserAttackTimer >= 50){
            //361 = wall attack
            float playerX = manager->getPlayer()->getXPosition() + manager->getPlayer()->getWidth() ;
            float playerY = manager->getPlayer()->getYPosition();

            float enemyX = process->getActor()->getXPosition() + (process->getActor()->getWidth() / 2);
            float enemyY = process->getActor()->getYPosition() + (process->getActor()->getHeight() / 2);

            float angleX = playerX - enemyX;
            float angleY = enemyY - playerY;
            float angle = (atan2(angleY, angleX) * 180) / (double) 3.141592;
            manager->enemyFire(process, angle);
            laserAttackTimer -= 50;
        }
    }
    //cases where nothing should be fired
    else if ((switchTimer >= 5000 && switchTimer <= 8000) || (switchTimer >= 9000 && switchTimer <= 10000) 
        || (switchTimer >= 11000 )){
    }
    //if not firing laser or pausing, shoot walls of bullets occasionally
    else{
        wallAttackTimer += delta;
        if (wallAttackTimer >= 1100){
        //361 = wall attack
        manager->enemyFire(process, 361);
        wallAttackTimer -= 1100;
        }
    }
    switchTimer += delta;
    bossAttackTimer -= delta;
    if (bossAttackTimer <= 0){
        //no attacks for 4 seconds after crazy attack
        currentBossAttack = NONE;
        bossAttackTimer = 4000;
        spreadAttackTimer = 0;
        laserAttackTimer = 0;
        wallAttackTimer = 0;
        switchTimer = 0;
    }
}

