#include "ActiveProcess.h"
#include "ProcessManager.h"
#include <SDL.h>

#ifndef CSCI437_AIVIEW_H
#define CSCI437_AIVIEW_H


class AIView {

private:
std::shared_ptr<ProcessManager> manager;
float flyingTurnAround, lobbingEnemyJump, lobbingEnemyFire, bossAttackTimer;
const float FLYING_TURN_INTERVAL = 3000;
const float LOBBING_JUMP_INTERVAL = 2000;
//wall: several walls of bullets are fired at the player
//lobbing up/down: lobbing bullets are fired on alternating sides, with an occasional bullet fired at the player
enum bossAttacks {NONE, WALL, LOBBING_DOWN, LOBBING_UP, LASER, SPREAD, CRAZY};
const int BOSS_ATTACK_NUM = 7;
int currentBossAttack;
//variable to track flying enemy movement turns and lobbing enemy jumps
bool flyingTurn, jumpingTime;
//bool to track if tyrantula has yet unleashed hell
bool bigAttackHappened;

//boss attack patterns
void wallAttack(unsigned long long delta, std::shared_ptr<ActiveProcess> process);
void bouncingAttack(unsigned long long delta, std::shared_ptr<ActiveProcess> process, bool dirFlag);
void laserAttack(unsigned long long delta, std::shared_ptr<ActiveProcess> process);
void spreadAttack(unsigned long long delta, std::shared_ptr<ActiveProcess> process);
void crazyAttack(unsigned long long delta, std::shared_ptr<ActiveProcess> process);
public:

AIView(const std::shared_ptr<ProcessManager> manager);
void makeDecision(unsigned long long delta);

};


#endif //CSCI437_AIVIEW_H
