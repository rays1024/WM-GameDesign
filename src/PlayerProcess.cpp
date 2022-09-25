#include "ActiveProcess.h"
#include "PlayerProcess.h"


//id is irrelevant to player process
//simply create the player
PlayerProcess::PlayerProcess(int id){
    if (id == 0){
        player = std::make_shared<PlayerActor>(SCREEN_WIDTH / 8, SCREEN_HEIGHT / 2, 80, 80);
    } 
    
    this->state = RUNNING;
}

PlayerProcess::PlayerProcess(int id,const std::shared_ptr<PlayerActor> player){
    this->player = player;
}

void PlayerProcess::update(unsigned long long deltaMs){
    player->update(deltaMs);
}